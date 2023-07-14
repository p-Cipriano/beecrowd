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

ull mod = pow(10,6);

ull n,k,l;

map<ull,ull>precal;

ull calc(ull n);

ull assign(ull n){

  map<ull,ull>::iterator it = precal.find(n);

  if(it == precal.end()){
    precal[n] = calc(n);
    return precal[n];
  }
  return  it->second;
}

ull calc(ull n){
  if(n==0)
    return 1;
  if(n==1)
    return k;
  if(n==2)
    return ((k*k)%mod+l)%mod;

  ull ans = assign(n/2);


  if(n%2==0){
    ans*=ans;
    ans%=mod;
    ull aux = assign(n/2-1);
    aux*= aux;
    aux%=mod;
    aux*=l;
    aux%=mod;
    ans+=aux;
    ans%=mod;
  }
  else{
    ull aux = ans;
    ans*= assign(n/2+1);
    ans%=mod;
    aux*= assign(n/2-1);
    aux%=mod;
    aux*=l;
    aux%=mod;
    ans+=aux;
    ans%=mod;
  }

  return ans;

}

int main(){ _

  while(cin >> n >> k >> l){

    k%=mod;
    l%=mod;
    n/=5;
    precal.clear();

    ull ans = calc(n);

    for(int i = 5; i>=0; i--){
      cout<<ans/((ll)pow(10,i));
      ans%=(ll)pow(10,i);
    }
    cout << endl;
    
  }

  
  return(0);
}
