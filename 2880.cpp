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
     
  string m;
  string crib;

  cin >> m >> crib;

  vector<bool> pos;
  pos.resize(m.size()-crib.size()+1,1);
  int ans = m.size()-crib.size()+1;

  for(int i=0; i<m.size(); i++){
    for(int j=max(0,i-(int)crib.size()+1);j<=min(i, (int)pos.size()-1); j++){
      if(m[i]==crib[i-j] && pos[j]){
        pos[j] = 0;
        ans--;
      }
    }
  }

  cout << ans << endl;

  return(0);
}
