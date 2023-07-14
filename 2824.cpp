#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

const int inf=0x3f3f3f3f;
const long long linf=0x3f3f3f3f3f3f3f3fll;
  
vector<vector<int>> bst;
string a,b;

int best(int x, int y){
  if(x==a.size()||y==b.size())
    return 0;

  if(a[x]==b[y]){
    if(bst[x+1][y+1]==-inf)
      bst[x+1][y+1] = best(x+1,y+1);
    return 1 + bst[x+1][y+1];
  }

  if(bst[x+1][y]==-inf)
    bst[x+1][y]=best(x+1,y);
  if(bst[x][y+1]==-inf)
    bst[x][y+1]=best(x,y+1);

  return max(bst[x+1][y], bst[x][y+1]);
}

int main(){ _
     
  cin >> a >> b;
  bst.clear();
  bst.resize(a.size()+1, vector<int>(b.size()+1, -inf));
  cout << best(0,0) << endl;
  return(0);
}
