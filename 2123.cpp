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

vector<vector<int>>gr;
vector<int>cp;
vector<int>con;
vector<int> vis;
int n, m, k;

bool dfs(int pos){

  //cout << pos << endl;

  if(pos<m){
    for(int i = 0; i < gr[pos].size(); i++){
      if(!vis[gr[pos][i]]){
        vis[gr[pos][i]]=1;
        
        if(dfs(gr[pos][i])){
          con[pos] = gr[pos][i];
          vis[gr[pos][i]]=0;
          return 1;
        }
        vis[gr[pos][i]]=0;
      }
    }
  }
  else{
    if(cp[pos-m]>0){
      cp[pos-m]--;
      return 1;
    }
    for(int i = 0; i < gr[pos].size(); i++){
      if(con[gr[pos][i]]==pos){
        if(dfs(gr[pos][i])){
          return 1;
        }
      }
    }
  }


  return 0;
}

int main(){ _
     
   int t = 1;

   while(cin >> n >> m >> k){
     
     cout << "Instancia " << t++ << endl;
     
     gr.clear();
     gr.resize(m+n);

     cp.clear();
     cp.resize(n);

     con.clear();
     con.resize(m, -2);

     vis.clear();
     vis.resize(n+m, 0);

     for(int i = 0; i<n; i++){
       cin >> cp[i];
     }
     for(int i = 0; i<k; i++){
        int s1, s2;
        cin >> s1 >> s2;
        s1--;
        s2--;

        gr[s2].pb(s1+m);
        gr[s1+m].pb(s2);
        
        if(cp[s1]>0 && con[s2]<0){
          cp[s1]--;
          con[s2]=s1+m;

        }
     }
     int ans = m;
     for(int i = 0; i < m; i++){

       
       if(con[i]<0){
        if(!dfs(i)){
          ans--;
        }
       }
     }
    
     cout << ans << endl << endl;
   }
  

  return(0);
}
