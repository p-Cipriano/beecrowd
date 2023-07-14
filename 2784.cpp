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

  vector<vector<ii>> adj;
  adj.resize(n+1);

  int u,v,p;

  for(int i = 0; i<m ; i++){
    cin >> u >> v >> p;
    adj[u].pb(make_pair(p,v));
    adj[v].pb(make_pair(p,u));
  }
  
  cin >> u;
  
  int mind=inf;
  int maxd=-1;
  queue<int> tov;
  vector<int> dis;
  dis.resize(n+1,inf);
  dis[u] = 0;
  
  tov.push(u);
  do{
    u = tov.front();
    //cout << endl<< u << endl;
    //cout << dis[u] << endl;
    tov.pop();
    //cout << endl;
    for(int i = 0; i < adj[u].size(); i++){
      //cout << adj[u][i].f << " " << adj[u][i].s << endl;
      //cout << dis[adj[u][i].s] << endl;
      if(dis[u]+adj[u][i].f < dis[adj[u][i].s]){
        dis[adj[u][i].s] = dis[u]+adj[u][i].f;
        tov.push(adj[u][i].s);
      }
    }
    
  }while(!tov.empty());
  
  for(int i = 1; i<n+1; i++){
    //cout << dis[i] << endl;
    if(dis[i]>0 && dis[i]<mind){
      mind = dis[i];
    }
    if(dis[i]>maxd)
      maxd = dis[i];
  }

  cout << maxd-mind << endl;
  
  return(0);
}
