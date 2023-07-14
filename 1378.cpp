#include <bits/stdc++.h>
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

const int inf=0x3f3f3f3f;
const long long linf=0x3f3f3f3f3f3f3f3fll;


ull norm(ll i, ll j){
  return i*i+j*j;
}

int main(){ _
  
  int ans;
  ull dist;
  vector<unordered_map<ull,int>> times;
  vector<ii> p;
  pair<unordered_map<ull,int>::iterator,bool> it;   
  int n;
  ii aux = mp(0,0);
  scanf("%d",&n);

  while(n){
  
    ans = 0;
    times.clear();
    p.clear();

    for(int i = 0; i < n; i++){
      scanf("%d%d", &aux.f, &aux.s);
      p.pb(aux);
      times.pb({});
      for(int j = 0; j<i; j++){

        dist = norm(p[i].f-p[j].f,p[i].s-p[j].s); 
        it = times[i].insert(mp(dist,1));
        
        if(!it.s){
          ans+=it.f->s;
          it.f->s++;
        }

        it = times[j].insert(mp(dist,1));
        if(!it.s){
          ans+=it.f->s;
          it.f->s++;
        }
      }
    }
    printf("%d\n", ans);
    scanf("%d", &n);
  }

  
  return(0);
}


