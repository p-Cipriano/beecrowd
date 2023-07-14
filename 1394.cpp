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
vector<int> vis;
queue<int> uncon;
int n, m, g;

bool dfs(int pos, int pre,  int pasp){

  int npas=pasp;

  int mx = max(pos,pre);
  int mn = min(pos,pre);

  if(gr[pos][pos]<gr[0][0]-1){
    //from mn to mx we do -
    npas-=min(pasp,min(gr[0][0]-1-gr[pos][pos], (pre>=pos)*(2*gr[mx][mn]-gr[mn][mx]) + (pre<pos)*gr[mn][mx]));
    gr[pos][pos]+=pasp-npas;
        //Prob
    gr[mn][mx]+=npas*((pre>=pos)-(pre<pos));
  }
  if(npas==0){
    return 0;
  }

  int aux; 

  for(int i=1; i<n;i++){
    if(!vis[i] && i!=pos){
      vis[i]=1;
      if(i>pos){
        aux = dfs(i, pos, min(npas, gr[i][pos]));
        npas-=min(npas, gr[i][pos])-aux;

      }
      else{
        aux = dfs(i, pos, min(npas, gr[pos][i]));
        npas-=min(npas,gr[pos][i])-aux;
      }
      vis[i]=0;
      if(npas==0)
        return 0;

    }
  }

  return npas;
}

int main(){ _
     
  
   cin >> n >> m >> g;

   while(n){

     gr.clear();
     gr.resize(n+1, vector<int>(n+1, m));
     for(int i = 0; i < n; i++){
       gr[i][i]=0;
     }

     vis.clear();
     vis.resize(n+1, 0);

     while(uncon.size())
      uncon.pop();


     for(int i = 0; i<g; i++){
        int s1, s2;
        char c;

        cin >> s1 >> c >> s2;
        
        gr[s1][s2]--;
        gr[s2][s1]--;
        
        if(c=='='){
          gr[s1][s1]++;
          gr[s2][s2]++;
        }
        else{
          gr[s2][s2]+=2;
        }

     }

     for(int i=1; i<n; i++){
       if(gr[0][i]>0){
         gr[0][0]+=2*gr[0][i];
         gr[0][i]=0;
         gr[i][0]=0;
       }
     }

     for(int i=1; i<n-1; i++){
       for(int j=i+1;j<n;j++){
         gr[i][i]+=gr[i][j];
         gr[j][j]+=gr[i][j];
       }
       if(gr[i][i]>=gr[0][0])
         uncon.push(i);
     }
     int flag = 0;
      
     while(uncon.size()>0){
        int aux = uncon.front();
        flag = dfs(aux, n+1, gr[aux][aux]-gr[0][0]+1);
        uncon.pop();
        if(flag!=0)
          break;
     }
     if(flag==0)
       cout << "Y" << endl;
     else
       cout << "N" << endl;

     cin >> n >> m >> g;

   }
  
  return(0);
}
