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
  
vector<ii> v;
vector<vector<ll>> bst;
int n,k;

ll best(int i, int k, int th){
  ll qt=0;
  if(k<=th)
    return 0;
  else if(i == n-1 && k<=th+v[i].f)
    return v[i].s;
  else if(i==n-1)
    return linf;

  if(bst[i+1][th]==-linf)
    bst[i+1][th]=best(i+1,k,th);
      
  if(bst[i+1][min(th+v[i].f,k)]==-linf){
    bst[i+1][min(th+v[i].f,k)]= best(i+1,k,th+v[i].f);
  }

  qt=min(bst[i+1][th],bst[i+1][th+v[i].f] + v[i].s);
  return qt;
}

int main(){ _
     
  ll ans;

  while(cin >> n >> k){
    ans = linf;

    v.clear();
    bst.clear();
    v.resize(n, make_pair(0,0));
    bst.resize(n, vector<ll>(k+1, -linf));

    for(int i = 0; i<n; i++){
      cin >> v[i].f >> v[i].s;
    }
    
    ans = best(0,k,0);
    if(ans<linf)
      cout << ans << endl;
    else
      cout << -1 << endl;
  }
  return(0);
}

