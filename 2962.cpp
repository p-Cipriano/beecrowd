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
     
  int m,n,k;
  int u,w,aux,root;

  cin >> m >> n >> k;

  vector<vector<int>> v;
  v.resize(k);

  for(int i=0;i<k;i++){
    v[i].resize(6,0);
    
    cin >> v[i][0] >> v[i][1] >> v[i][2];
    
    if(v[i][0]-v[i][2] <= 0 || v[i][1]+v[i][2] >= n){
      v[i][3] = -1;
    }
    if(v[i][0]+v[i][2] >= m || v[i][1]-v[i][2] <= 0){
      if(v[i][3]==-1){
        cout << "N" << endl;
        return 0;
      }
      v[i][3] = 1;
    }

    v[i][4] = i;

    v[i][5] = 0;

    for(int j=0;j<i;j++){
      u = i;
      w = j;
      if(pow(v[u][0]-v[w][0],2)+pow(v[u][1]-v[w][1],2)<=pow(v[u][2]+v[w][2],2)){
        while(v[u][4]!=u || v[w][4]!=w){
          u = v[u][4];
          w = v[w][4];
        }
        if(u!=w){
          if(v[u][3]*v[w][3] < 0){
            cout << "N" << endl;
            return 0;
          }
          
          if(v[u][5] > v[w][5]){
            v[w][4] = u;
            if(v[u][3]==0)
              v[u][3] = v[w][3]; 
            root = u;
          }
          else if(v[u][5] < v[w][5]){
            v[u][4] = w;
            if(v[w][3]==0)
              v[w][3] = v[u][3];
            root = w;
          }
          else{
            v[w][4] = u;
            v[u][5]++;
            if(v[u][3]==0)
              v[u][3] = v[w][3]; 
            root = u;
          }
          u = i;
          w = j;
          while(v[u][4]!=root || v[w][4]!=root){
            aux = v[u][4];
            v[u][4] = root;
            u = aux;

            aux = v[w][4];
            v[w][4] = root;
            w = aux;
          }
        }
      }
    }

  }

  cout << "S" << endl;
  return(0);
}
