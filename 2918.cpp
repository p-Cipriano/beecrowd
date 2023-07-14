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

int main(){ _
     

  ull l,r;
  ull lcp, rcp;
  int fl,fr;
  double aux;
  ull  ansl,ansr;
  ll mod = pow(10,9)+7;
  
  while(cin >> l >> r){
    lcp=l;
    rcp=r;
    l--;
    ansr=0;
    ansl=0;
    aux=pow(10,10);

    //cout << l << " " << r << endl;

    for(int i=11;i>0;i--){
      fl = floor((double)l/aux);
      fr = floor((double)r/aux);
      
      ansl+=(ull)(45*(i-1)*fl*aux/10)%mod;
      ansl%=mod;
      ansl+=(ull)((fl-1)*fl*aux/2)%mod;
      ansl%=mod;
      ansl+=(ull)(fl*(l-fl*aux+1))%mod;
      ansl%=mod;
      l-=fl*aux;

      ansr+=(ull)(45*(i-1)*fr*aux/10)%mod;
      ansr%=mod;
      ansr+=(ull)((fr-1)*fr*aux/2)%mod;
      ansr%=mod;
      ansr+=(ull)(fr*(r-fr*aux+1))%mod;
      ansr%=mod;
      r-=fr*aux;

        //cout << l << endl;
        //cout << ansl << endl;
      aux/=10;
    }
    cout<<(ansr-ansl)%mod<<endl;
  }

  return(0);
}
