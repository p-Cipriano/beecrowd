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
  cin >> n;

  int u,v,w;

  vector<vector<int>> edg;
  map<int,int> pai;
  map<int,int> h;
  map<int,int> pai2;
  map<int,int> h2;
  
  edg.resize(n);
  
  for(int i=0;i<n;i++){
    cin >> u >> v >> w;
    edg[i].resize(3);
    edg[i][0] = w;
    edg[i][1] = u;
    edg[i][2] = v;
    pai[u]=u;
    h[u] = 0;
    pai[v]=v;
    h[v] = 0;
    pai2[u] = u;
    h2[u] = 0;
    pai2[v] = v;
    h2[v] = 0;
  }
  
  sort(edg.begin(), edg.end(),[](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];});
  
  int ans1 = 0;
  int ans2 = 0;
  int root, aux;

  for(int i=0;i<n;i++){
    //union find
    u = edg[i][1];
    v = edg[i][2];
    while(pai[u] != u || pai[v]!=v){
      u = pai[u];
      v = pai[v];
    }
    root = u;
    if(u!=v){
      if(h[u] > h[v])
        pai[v] = u;
      else if(h[v] > h[u]){
        pai[u] = v;
        root = v;
      }
      else{
        pai[v] = u;
        h[v]++;
      }
           
      ans1+=edg[i][0];
    } 
    
    u = edg[i][1];
    v = edg[i][2];

    while(u!=root || v!=root){
      aux = pai[u];
      pai[u] = root;
      u = aux;
        
      aux = pai[v];
      pai[v] = root;
      v = aux;
    }
  }
  for(int i=n-1;i>=0;i--){
    //union find
    u = edg[i][1];
    v = edg[i][2];
    while(pai2[u] != u || pai2[v]!=v){
      u = pai2[u];
      v = pai2[v];
    }
    root = u;
    if(u!=v){
      if(h2[u] > h2[v])
        pai2[v] = u;
      else if(h2[v] > h2[u]){
        pai2[u] = v;
        root = v;
      }
      else{
        pai2[v] = u;
        h2[v]++;
      }
           
      ans2+=edg[i][0];
    } 
    
    u = edg[i][1];
    v = edg[i][2];

    while(u!=root || v!=root){
      aux = pai2[u];
      pai2[u] = root;
      u = aux;
        
      aux = pai2[v];
      pai2[v] = root;
      v = aux;
    }
  }
  cout << ans2 << endl;
  cout << ans1 << endl;

  return(0);
}
