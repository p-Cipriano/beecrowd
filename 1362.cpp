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
queue<int>uncon;
vector<int> vis;
int n, m;

bool dfs(int pos){

  if(pos<m){
    if(!vis[gr[pos][0]]){
    vis[gr[pos][0]]=1;
    if(dfs(gr[pos][0]+m)){
      con[pos] = gr[pos][0];
      vis[gr[pos][0]]=0;
      return 1;
    }
    vis[gr[pos][0]]=0;
    
    }
    if(!vis[gr[pos][1]]){
      vis[gr[pos][1]]=1;
      if(dfs(gr[pos][1]+m)){
        con[pos] = gr[pos][1];
        vis[gr[pos][1]]=0;
        return 1;
      }
      vis[gr[pos][1]]=0;
    }
  }
  else{
    if(cp[pos-m]>0){
      cp[pos-m]--;
      return 1;
    }
    for(int i = 0; i < gr[pos].size(); i++){
      if(con[gr[pos][i]]==pos-m){
        if(dfs(gr[pos][i])){
          //tcon[pos-m].erase(gr[pos][i]);
          return 1;
        }
      }
    }
  }


  return 0;
}

int main(){ _
     
   int t;

   map<string, int>sizes;
   sizes["XS"] = 0;
   sizes["S"] = 1;
   sizes["M"] = 2;
   sizes["L"] = 3;
   sizes["XL"] = 4;
   sizes["XXL"] = 5;
  
   cin >> t;

   for(int k = 0; k < t; k++){
     
     cin >> n >> m;

     gr.clear();
     gr.resize(m+6);

     cp.clear();
     cp.resize(6, n/6);

     con.clear();
     con.resize(m, -1);

     vis.clear();
     vis.resize(6, 0);

     while(uncon.size())
      uncon.pop();

     tcon.clear();
     tcon.resize(6);

     for(int i = 0; i<m; i++){
        string s1, s2;
        cin >> s1 >> s2;
        
        gr[i].pb(sizes[s1]);
        gr[i].pb(sizes[s2]);
        gr[sizes[s1]+m].pb(i);
        gr[sizes[s2]+m].pb(i);

        if(cp[sizes[s1]]>0){
          con[i] = sizes[s1];
          cp[sizes[s1]]--;
        }
        else if(cp[sizes[s2]]>0){
          con[i] = sizes[s2];
          cp[sizes[s2]]--;
        }
        else{
          uncon.push(i);
        }
     }
     int flag = 1;
     while(uncon.size()>0){
        flag = dfs(uncon.front());
        uncon.pop();
        if(flag==0)
          break;
     }
     if(flag==1)
       cout << "YES" << endl;
     else
       cout << "NO" << endl;

   }
  
  return(0);
}
