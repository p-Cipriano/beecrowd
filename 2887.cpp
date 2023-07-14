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

vector<int>hei;
vector<vector<int>> adj;
vector<int>in;
vector<int>out;
vector<vector<int>>pai;
int t=1;
int w = 10;

bool ances(int a, int b){
  return in[a] <= in[b] && out[a] >= out[b];
}

int lca(int a, int b){

  if(ances(a,b)) return a;
  if(ances(b,a)) return b;

  for(int i = w-1; i>= 0; i--){
    if(!ances(pai[i][a],b)){
      a = pai[i][a];
    }
  }

  return pai[0][a];
}

void buildTree(int v, int h){
  
  in[v] = t++;
  hei[v] = h;

  for(int i = 0; i < adj[v].size(); i++){
    if(!in[adj[v][i]]){
      pai[0][adj[v][i]] = v;
      buildTree(adj[v][i], h+1);
    }
  }
  out[v] = t++;
}

int main(){ _
  int n,q;

  cin >> n >> q;

  adj.resize(n);
  in.resize(n,0);
  out.resize(n);
  hei.resize(n);
  pai.resize(w, vector<int>(n));
  int a, b;
  int c, d;

  for(int i = 0; i<n-1;i++){
    cin >> a >> b;
    a--;
    b--;
    adj[b].pb(a);
    adj[a].pb(b);
  }

  buildTree(0, 0);

  pai[0][0] = 0;

  for(int i = 1; i < w; i++){
    for(int j = 0; j < n; j++){
      pai[i][j] = pai[i-1][pai[i-1][j]];
    }
  }


  for(int i = 0; i < q; i++){
    cin >> a >> b;
    cin >> c >> d;
    a--;
    b--;
    c--;
    d--;

    int ans1 = 0;
    int ans2 = 0;

    int ab = lca(a,b);
    int abc = lca(ab,c);
    int abd = lca(ab,d);


    if(hei[ab] > max(hei[abc], hei[abd])){
      cout << 0 << endl;
      continue;
    }

    int ac = lca(a,c);
    int ad = lca(a,d);
    int cd = lca(c,d);
    int bc = lca(b,c);
    int bd = lca(b,d);

    if(ac!=ad || ac==cd){
      ans1 = max(hei[ac], hei[ab]);
      ans1 -= max(hei[ad], hei[ab]);
      ans1 = abs(ans1);
      ans1++;
    }

    if(bc!=bd || bc==cd){
      ans2 = max(hei[bc], hei[ab]);
      ans2 -= max(hei[bd], hei[ab]);
      ans2 = abs(ans2);
      ans2++;
    }

    if(ans1*ans2>0){
      cout << ans1+ans2-1 << endl;
    }
    else{
      cout << ans1+ans2 << endl;
    }
  }
  
  return(0);
}
