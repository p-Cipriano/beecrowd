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

  vector<ull>F;
  vector<int>prime;
  vector<int>in;
  F.resize(pow(10,7)+1, 1);
  //prime.pb(1);

  F[0] = 0;
  F[1] = 0;

  for(ull i = 2; i <= pow(10,7); i++){
    
    if(F[i]){
      //prime.pb(i);
      for(ull j = i*i; j < F.size(); j+=i){
          F[j] = 0;        
      }
    }
  }

  for(ull i = 1; i <=pow(10,7); i++){
    F[i]+=F[i-1];
  }

  int a,b;
  cin >> a >> b;

  if(a==b){
    cout << "?" << endl;
    return 0;
  }

  if(a>b) swap(a,b);

  int n = b-a;
  int k = F[b]-F[max(0,a-1)];

  if(k==0){
    cout << "Bob" << endl;
    return 0;
  }
  else if(k==1){
    cout << "Alice" << endl;
    return 0;
  }

  //cout << n << " " << k << endl;

  ll ans = 0;
  ll pw = 2;

  while(1){

    ll it = ((n+k-1)/pw);
    ll mn = (n/pw) + ((k-1)/pw); 
    if(it==0 && mn==0) break;
    ans+=it-mn;
    pw*=2;
  }
  //cout << ans << endl;

  if(ans>0) cout << "Bob" << endl;
  else cout << "Alice" << endl;
  
  return(0);
}
