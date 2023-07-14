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
  int rev;

  e(int ne, int capc, int r){
    c = capc;
    n = ne;
    fl = 0;
    rev = r;
  }

};

int n,m,a;

int k;

vector<vector<e>> gr;
vector<vector<vector<e>>> grafo;
vector<vector<int>> level;
vector<vector<bool>> vis;

void endFlux(){
  for(int i = 0; i < k+1; i++){
    for(int j = 0; j < grafo[i].size(); j++){
      for(int k = 0; k < grafo[i][j].size(); k++){
        grafo[i][j][k].fl = 0;
      }
    }
  }
}

int dfs(int s, int day,  int t, int flx){

  vis[day][s] = 1;

  if(s==t)
    return flx;

  for(int i = 0; i < grafo[day][s].size(); i++){
    
    int nxtDay = day + 1 - 2*(grafo[day][s][i].c==0);

    if(nxtDay>=k+1 || nxtDay < 0) continue;
    
    int neigh = grafo[day][s][i].n;
    int cpty = grafo[day][s][i].c - grafo[day][s][i].fl;

    if(!vis[nxtDay][neigh] && cpty > 0){
      
      int aux = dfs(neigh, nxtDay, t, min(flx, cpty));

      if(aux){
        grafo[day][s][i].fl+=aux;
        grafo[nxtDay][neigh][grafo[day][s][i].rev].fl -= aux;

        return aux;
      }
    }
  }
  
  return 0;
}

int flux(){

  int itans;

  grafo.clear();

  while(grafo.size()<a+n)
    grafo.pb(gr);

  vis.clear();
  vis.resize(a+n+1, (vector<bool>(n,0)));
  
  int ans=0;

  int l = 0;
  int r = a+n;

  while(1){

    k = ceil(((double)l+r)/2);

    do{
        
      for(int i = 0; i<k+1; i++){
        for(int j = 0; j<n; j++)
          vis[i][j] = 0;
      }

      itans = dfs(0, 0, n-1, inf);
      ans+=itans;

      if(ans>=a)
        break;

    }while(itans > 0);

    if(ans>=a){

      r = k;

      if(r-l == 1)
        return k;
    }
    else{
      l = k;

      if(r-l == 1)
        return k+1;
    }
    
    endFlux();
    ans = 0;
  }
  return -1;
}

int main(){ _
     
  cin >> n >> m >> a;

  while(n){

    int x,y,z;
    
    gr.clear();
    gr.resize(n);

    grafo.clear();

    for(int i=0; i<m; i++){
      cin >> x >> y >> z;
      x--;
      y--;
      gr[x].pb(e(y,z,gr[y].size()));
      gr[y].pb(e(x,0,gr[x].size()-1));
    }
    
    for(int i = 0; i<n; i++){
      gr[i].pb(e(i, inf, gr[i].size()+1));
      gr[i].pb(e(i, 0, gr[i].size()-1));
    }

    cout << flux() << endl;   

    cin >> n >> m >> a;
  }

  return(0);
}
