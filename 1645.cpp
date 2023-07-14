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
vector<vector<ull>> bst;
int n,k;

ull best(int i, int k, int size){
  ull qt=0;
  if(k==size)
    return 1;
  for(int j=i+1; j<n;j++){
    if(v[j]>v[i]){
      if(bst[j][size+1]==-inf)
        bst[j][size+1]=best(j,k,size+1);
      qt+=bst[j][size+1];
    }
  }
  return qt;
}

int main(){ _
     
  ull ans;

  cin >> n >> k;
  while(n){
    ans = 0;
    v.clear();
    bst.clear();
    v.resize(n+1);
    bst.resize(n+1, vector<ull>(k+1, -inf));
    for(int i = 0; i<n; i++){
      cin >> v[i];
    }
    for(int i = 0; i<n; i++){
      ans += best(i,k,1);
    }
    cout << ans << endl;
    cin >> n >> k;
  }
  return(0);
}
