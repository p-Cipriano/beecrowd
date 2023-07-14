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


vector<int> pathSize;

vector<int> ans;

vector<vector<ii>> adj;

vector<int>visited;
vector<ii>cycle; 

int cycledfs(int v, int pv){

  visited[v]=1;

  int cycleid = -1;
  int aux = -1;

  for(auto w:adj[v]){
    if(visited[w.s]==1 && w.s!=pv){
      cycle[w.s].f=pathSize[v]-pathSize[w.s]+w.f;
      cycle[w.s].s=w.s;
      cycle[v]=cycle[w.s];
      cycleid =  w.s;
    }
    else if(w.s!=pv){
      pathSize[w.s]=pathSize[v]+w.f;
      aux = cycledfs(w.s,v);
      if(aux!=-1 && aux!=v){
        cycleid=aux;
        cycle[v]=cycle[cycleid];
      }
    }
  }
  visited[v]=2;
  return cycleid;
}

void dfs(int x, int m, int cycleEntry, int px){

  if(cycle[x]!=cycle[cycleEntry]){
    cycleEntry = x;
  }
  visited[x]=1;

  if(cycle[x].f>=m)
    ans[x]=cycle[x].f;

  for(auto w:adj[x]){
    
    if(!visited[w.s])
      dfs(w.s,m, cycleEntry, x);
    else if(cycle[w.s]==cycle[x] && w.s!=cycleEntry && w.s!=px){
      dfs(w.s,m, cycleEntry, x);
    }
    
    ans[x]=min(ans[x],ans[w.s]+2*w.f);

  }
}

int main(){ _
  int s,t;
  int a,b,c;
  int q;
  int x,m;

  int aux;
  int sub;

  while(cin >> s >> t){

    
    adj.clear();
    adj.resize(s+1);

    visited.clear();
    visited.resize(s+1,0);

    pathSize.clear();
    pathSize.resize(s+1,-1);

    cycle.clear();
    cycle.resize(s+1);

    for(int i=0;i<t;i++){
      cin >> a >> b >> c;
      cycle[a] = make_pair(-1,-1);
      cycle[b] = make_pair(-1,-1);
      adj[a].pb(make_pair(c,b));
      adj[b].pb(make_pair(c,a));
    }

    pathSize[1] = 0;
    cycledfs(1,-1);

    cin >> q;

    for(int i=0;i<q;i++){
      cin >> x >> m;

      visited.clear();
      visited.resize(s+1,0);
      
      pathSize.clear();
      pathSize.resize(s+1,-1);

      pathSize[x]=0;

      ans.clear();
      ans.resize(s+1,inf);
      
      dfs(x,m,x,x);

      if(ans[x]==inf)
        ans[x]=-1;
      cout << ans[x] << endl;
    }
  }
  return(0);
}
