#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

const int inf=0x3f3f3f3f;
const long long linf=0x3f3f3f3f3f3f3f3fll;
  
vector<vector<vector<int>>> bst;
vector<vector<int>> pils;
int n;

int best(int x, int y, int z){
  if(x+y+z==0)
    return 1;

  int aux = 0;

  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      for(int k=0;k<2;k++){
        if((pils[x][0]*i+pils[y][1]*j+pils[z][2]*k)%3==0 && i+j+k!=0 && x-i>=0 && y-j>=0 && z-k>=0){
          if(bst[x-i][y-j][z-k]==-inf)
            bst[x-i][y-j][z-k] = best(x-i, y-j,z-k);
          if(bst[x-i][y-j][z-k]==1)
            return 1;
        }
      }
    }
  }
  return 0;
}

int main(){ _
     
  cin >> n;
  while(n){

    bst.clear();
    bst.resize(n+1, vector<vector<int>>(n+1, vector<int>(n+1,-inf)));
    pils.clear();
    pils.resize(n+1, vector<int>(3,0));
    for(int i=1; i<n+1;i++){
      for(int j=0;j<3;j++){
        cin >> pils[i][j];
      }
    }
    cout << best(n,n,n) << endl;
    cin >> n;
  }
  return(0);
}
