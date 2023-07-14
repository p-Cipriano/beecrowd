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

ull mx = pow(10,9)+6;

int main(){ _

  vector<int>F;
  vector<int>prime;
  vector<int>in;
  F.resize(2*pow(10,7), 1);
  prime.pb(1);

  for(ull i = 2; i <= 2*pow(10,7); i++){
    
    if(F[i]){
      prime.pb(i);
      for(ull j = i*i; j < F.size(); j+=i){
          F[j] = 0;        
      }
      if(prime.size()==pow(10,6)){
        //cout << prime[prime.size()-1] << endl;
        break;
      }
    }
  }

  int n;
  cin>>n;

  for(int k = 0; k< n; k++){
    
    int l;
    cin >> l;
    in.clear();
    in.resize(l);

    for(int i = 0; i < l; i++){
      cin >> in[i];
    }
    sort(in.begin(), in.end());
    for(int j = 0; j < prime.size(); j++){
      if(!binary_search(in.begin(),in.end(),prime[j])){
        cout << prime[j]-1 << endl;
        break;
      }
    }
    
  }
  
  return(0);
}
