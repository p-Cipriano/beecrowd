#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int inf=0x3f3f3f3f;
const long long linf=0x3f3f3f3f3f3f3f3fll;

int main(){ _
     
  ll n;
  cin >> n;

  ll sn = sqrt(n);

  int ans = 0;

  if(n%2==0){
    ans++;
    while(n%2==0)
      n/=2;
  }
  if(n%3==0){
    ans++;
    while(n%3==0)
      n/=3;
  }

  for(int i = 6;i<=sn+1;i+=6){
    if(n%(i-1)==0){
      ans++;
      while(n%(i-1)==0){
        n/=i-1;
      }
    }
    if(n%(i+1)==0){
      ans++;
      while(n%(i+1)==0)
        n/=i+1;
    }
    if(n==1)
        break;
  }

  if(n>1)
    ans++;
  cout << pow(2,ans)-ans-1 << endl;
  
  return(0);
}
