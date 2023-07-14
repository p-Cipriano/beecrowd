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
  
vector<int> v;
vector<vector<int>> bst;
int n;

bool best(int i, int l, int r){
  if(abs(l-r)>5)
    return 0;
  else if(i==n-1 && abs(l-r-v[i])>5 && abs(l-r+v[i])>5)
    return 0;
  else if(i==n-1)
    return 1;

  if(bst[i+1][abs(l-r-v[i])]==-1)
    bst[i+1][abs(l-r-v[i])]=best(i+1,l,r+v[i]);
      
  if(bst[i+1][abs(l+v[i]-r)]==-1){
    bst[i+1][abs(l+v[i]-r)]= best(i+1, l+v[i],r);
  }

  return (bst[i+1][abs(l+v[i]-r)] || bst[i+1][abs(l-r-v[i])]);
}

int main(){ _
     
  bool ans;
  int t;
  cin >> t;

  for(int j = 0; j<t ; j++){
    cin >> n;
    ans = 0;

    v.clear();
    bst.clear();
    v.resize(n, 0);
    bst.resize(n, vector<int>(16,-1));

    for(int i = 0; i<n; i++){
      cin >> v[i];
    }
    
    ans = best(0,0,0);
    
    if(ans)
      cout << "Feliz Natal!" << endl;
    else
      cout << "Ho Ho Ho!" << endl;
  }
  return(0);
}

