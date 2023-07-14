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

vector<vector<int>> a;
vector<vector<vector<vector<vector<int>>>>> dist;
vector<ii> xy; 
vector<vector<int>>fx;
int n,m,x,y;

int path(int r, int c, int lx, int ly, int right){
  
  int ans = inf+1;
  int aux=0;
  int nlx;
  int nly;
  int hm;

  if(r==n-1){
    nlx=lx-(fx[m-1][1]-fx[c][1])-(a[r][c]==0);
    nly=ly-(fx[m-1][2]-fx[c][2])-(a[r][c]<0);
  
    if(nlx>=0 && nly>=0)
      return fx[m-1][0]-fx[c][0]+a[r][c];

    return inf+1;
  }
  
  nlx=lx-(a[r][c]==0);
  nly=ly-(a[r][c]<0);

  if(nlx<0 || nly< 0)
    return inf+1;

  hm = a[r][c];
  

  if(dist[r+1][c][nlx][nly][0]==inf){
    
    dist[r+1][c][nlx][nly][0] = path(r+1,c,nlx,nly,0);
  }
  if(dist[r+1][c][nlx][nly][0]<inf){
    ans=dist[r+1][c][nlx][nly][0]+hm;
  }

  if(dist[r+1][c][nlx][nly][1]==inf){
    dist[r+1][c][nlx][nly][1] = path(r+1,c,nlx,nly,1);
  }
  if(dist[r+1][c][nlx][nly][1]<inf){
    ans=min(ans, dist[r+1][c][nlx][nly][1]+hm);
  }
  
  if(right!=0 && c<m-1){
    if(dist[r][c+1][nlx][nly][1]==inf){
      dist[r][c+1][nlx][nly][1]=path(r,c+1,nlx,nly, 1);
    }
    if(dist[r][c+1][nlx][nly][1]<inf){
      ans=min(ans, dist[r][c+1][nlx][nly][1]+hm);
    }
  }

  if(right!=1 && c>0){
    if(dist[r][c-1][nlx][nly][0]==inf){
      dist[r][c-1][nlx][nly][0]=path(r,c-1,nlx,nly, 0);
    }
    if(dist[r][c-1][nlx][nly][0]<inf){
      ans=min(ans, dist[r][c-1][nlx][nly][0]+hm);
    }
  }
  
  return ans;
}

int main(){ _
     
  
  int ans;
  a.resize(101,vector<int>(101,0));
  fx.resize(101, vector<int>(3,0));
  xy.resize(101);
  dist.resize(101, vector<vector<vector<vector<int>>>>(101, vector<vector<vector<int>>>(21, vector<vector<int>>(21,
  vector<int>(2)))));
  

  while(cin >> n >> m >> x >> y){
    
    ans=0;

    
    for(int i = 0; i<n; i++){
      xy[i]=mp(0,0);
      if(i>0)
        xy[i] = xy[i-1];
      for(int j = 0; j<m; j++){
        cin >> a[i][j];
        
        xy[i].f+=(a[i][j]==0);
        xy[i].s+=(a[i][j]<0);
        
        if(i==n-1){
          fx[j][0]=a[i][j];
          fx[j][1]=(a[i][j]==0);
          fx[j][2]=(a[i][j]<0);

          if(j>0){
            fx[j][0]+=fx[j-1][0];
            fx[j][1]+=fx[j-1][1];
            fx[j][2]+=fx[j-1][2];
          }
        }
      }
    }
    for(int i=0; i<n+1; i++){
      for(int j=0; j<m+1; j++){
        for(int k=max(0,x-xy[i].f);k<=x; k++){
          for(int l=max(0,y-xy[i].s);l<=y;l++){
              dist[i][j][k][l][0]=inf;
              dist[i][j][k][l][1]=inf;
          }
        }
      }
    }
    ans = path(0,0,x,y,1);

    if(ans>=inf)
      cout << "Impossivel" << endl;
    else
      cout << ans << endl;


  }
  
  return(0);
}
