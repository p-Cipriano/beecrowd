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

vector<vector<int>> adj;
vector<int> vis;  
vector<vector<int>> comp;

void visit(int j, int label){
  if(vis[j]!=-1)
    return;
  comp[label].pb(j);
  vis[j] = label;
  for(auto k: adj[j]){
    visit(k,label);
  }
  return;
}

int main(){ _
  
  int n;
  int v,e;
  char ev1, ev2;
  int ans = -1;

  cin >> n;

  for(int i = 0; i<n; i++){

    cout << "Case #" << i+1 << ":" << endl;
    cin >> v;
    cin >> e;
    
    adj.clear();
    vis.clear();
    comp.clear();

    adj.resize(v);
    vis.resize(v,-1);
    ans = 0;
    comp.resize(v);

    for(int j=0; j<e; j++){
      cin >> ev1 >> ev2;
      adj[(int)ev1-97].pb((int)ev2-97);
      adj[(int)ev2-97].pb((int)ev1-97);
    }

    //for(int j=0;j<v;j++){
      //sort(adj[j].begin(), adj[j].end());
    //}

    for(int j=0; j<v; j++){
      if(vis[j] == -1){
        visit(j,ans);
        ans++;
      }
    }
    for(int j=0; j<ans; j++){
      sort(comp[j].begin(), comp[j].end());
      for(int k=0;k<comp[j].size();k++)
        cout << char(comp[j][k]+97) << ",";
      cout << endl;
    }
    cout << ans << " connected components" << endl << endl;
      
  }
  
  return(0);
}
