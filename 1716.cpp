#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")

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

pair<ull, ull>  fat(ull n){
  ull p=1;

  for(ull i = 2; i<sqrt(n); i++){
    if(n%i==0){
      p=i;
      n/=i;
      break;
    }
  }

  return mp(p,n);

}

pair<ll,ll> euclid(ll a, ll b, ll n){
  if(a==1)
    return mp(1,0);

  pair<ll, ll> ans = euclid(b, a%b, n);

  if(ans.f<0)
    ans.f+=n;
  if(ans.s<0)
    ans.s+=n;

  ll aux;

  ll q = ((ll)(a/b)*ans.s);

  q%=n;

  if(q < 0)
    q+=n;

  if(ans.f>=q)
    aux = ans.f-q;

  else
    aux = (ans.f+n)-q;


  //cout << ans.s%n << " " << aux << " = " << ans.f << " + " << q << endl;
    
  return mp(ans.s%n, aux%n);
}

ull exp(ull c, ull d, ull n){
  ull ans = 1;

  while (d>0){

    if(d%2)
      ans*=c;

    ans%=n;

    d/=2;

    c = (c*c)%n;
  }

  return ans%n;
}

int main(){ _
     


  ull n,e,c;

  cin >> n >> e >> c;

  pair<ull, ull> pq = fat(n);

  pq.f--;
  pq.s--;

  //cout << pq.f << " " << pq.s << endl;

  ll d = euclid(pq.f*pq.s, e, pq.f*pq.s).s;

  //cout << d << endl;

  if(d<0)
    d+=n;

  cout << exp(c,d,n) << endl;



  return(0);
}
