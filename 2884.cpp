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
  
  int n,m;
  cin >> n >> m;
  vector<bool> ac;
  vector<bool> start;
  vector<set<int>> psum;
  ac.resize(m,0);
  start.resize(m,0);
  psum.resize(n);

  int ones,l,k;

  cin >> ones;

  for(int i = 0; i < ones; i++){
    cin >> k;
    ac[k-1]=1;
  }
  

  for(int i = 0; i<n; i++){
    if(ones==0){
      cout << i << endl;
      break;
    }
    cin >> l;


    for(int j=0;j<l;j++){
      cin >> k;

      psum[i].insert(k);

      if(ac[k-1]){
        ac[k-1]=0;
        ones--;
      }
      else{
        ac[k-1]=1;
        ones++;
      }
    }
  }
  if(ones){
    for(int i = 0; i<n-1; i++){
      for(auto g: psum[i]){
        if(ac[g-1]){
          ac[g-1]=0;
          ones--;
        }
        else{
          ac[g-1]=1;
          ones++;
        }
      }
      
      if(ones==0){
        cout << i+n+1 << endl;
        break;
      }
    }
    if(ones)
      cout << -1 << endl;
  }

  return(0);
}
