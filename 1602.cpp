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

int main(){ _

  vector<int>F;
  vector<int>prime;
  F.resize(2*pow(10,6)+1, 1);

  for(int i = 2; i <= sqrt(F.size()); i++){
    
    if(F[i]){
      prime.pb(i);
      for(int j = i*i; j < F.size(); j+=i){
          F[j] = 0;        
      }
    }
  }

  for(int i = 0; i<prime.size(); i++){
    ull aux = prime[i]*prime[i];
    int pow = 3;
    while(aux<F.size()){
      for(int j = 0; j < pow; j++){
        if(prime[j] == pow){
          F[aux] = 1;
          break;
        }
        else if(pow < prime[j])
          break;
      }

      aux*=prime[i];
      pow++;
    }
  }

  for(int i = 3; i<F.size(); i++){
    F[i]+=F[i-1];
  }

  int n;

  while(cin>>n){
    
    /*for(int i = 2; i <= 100; i++){
      cout << F[i]-F[i-1] << " " << i << endl;
    }*/

    cout << F[n] << endl;
  }
  
  return(0);
}
