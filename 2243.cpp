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
     
  int n;
  int ans=1;
  cin >> n;
  vector<int> t;
  t.resize(n);

  for(int i=0; i<n; i++){
    cin>>t[i];
    if(i==0||i==n-1){
      t[i] = 1;
    }
    else{
      t[i]=min(t[i-1]+1, t[i]);
    }
    cout<<t[i]<<endl;
    for(int j = i-1; j>=0; j--){
      if(t[j]>t[j+1]+1){
        t[j]=t[j+1]+1;
      }
      else
        break;
    }
  }
  cout << endl << endl;
  for(int i=0; i<n; i++){
    cout << t[i] << endl;
    ans=max(ans,t[i]);
  }
  cout << endl;

  cout<<ans<<endl;

  return(0);
}
