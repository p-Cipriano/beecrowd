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

class e{
  public:

  int n;
  int c;
  int fl;

  e(int ne, int ca, int flw=0){
    n = ne;
    c = ca;
    fl = flw;
  }
};

int n,m;
vector<vector<e>>grafo;
vector<int>level;
vector<int>delta;


bool bfs(int s, int t){
  level.clear();
  level.resize(n+m+2, inf);
  level[s] = 0;

  queue<int> q;
  q.push(s);

  while(!q.empty()){
    int aux = q.front();
    q.pop();
    
    for(int i = 0; i < grafo[aux].size(); i++){
      if(level[grafo[aux][i].n] == inf && grafo[aux][i].c>grafo[aux][i].fl){
        level[grafo[aux][i].n] = level[aux]+1;
        q.push(grafo[aux][i].n);
      }
    }
  }

  return level[t] != inf;
}

int dfs(int s, int t, int flx){
  if(s==t)
    return flx;

  for(int i = 0; i < grafo[s].size(); i++){
    
    int neigh = grafo[s][i].n;

    if(level[neigh] == level[s]+1 && grafo[s][i].c > grafo[s][i].fl){
      int aux = dfs(neigh , t, min(flx, grafo[s][i].c - grafo[s][i].fl));
      if(aux){

        grafo[s][i].fl+=aux;
      
        for(int j = 0; j < grafo[neigh].size(); j++){
          if(grafo[neigh][j].n == s){
            grafo[neigh][j].fl -= aux;
            break;
          }
        }
        return aux;
      }
    }
  }
  
  return 0;
}

int flux(){
  int ans = 0;

  while(bfs(0, grafo.size()-1)){
    int itans = 0;
    do{
      ans+=itans;
      itans = dfs(0,grafo.size()-1, inf);

    }while(itans > 0);
  }

  return ans;
}

int main(){ _

  int aux;
     
  while(cin >> n >> m){

    delta.clear();
    delta.resize(m);

    grafo.clear();
    grafo.resize(n+m+2);


    int sum = 0;

    for(int i = 1; i<n+1; i++){
      cin >> aux;
      grafo[i].pb(e(m+n+1,aux));
    }

    for(int i = 0; i<m; i++){
      cin >> delta[i];
    }
    for(int i = n+1; i<m+n+1; i++){

      cin >> aux;
      sum+=aux;
      grafo[0].pb(e(i,aux));
      
      for(int j = 0; j<delta[i-n-1]; j++){
        cin >> aux;
        grafo[i].pb(e(aux, inf));
        grafo[aux].pb(e(i, 0));
      }
    } 
    
    cout << sum-flux() << endl;
    

  }
  
  return(0);
}
