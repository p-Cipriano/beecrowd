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

int z,b;
vector<int> rou;
vector<int> balls;
vector<vector<vector<int>>> bst;

int best(int p, int l, int r){

  if(p>=b)
    return 0;

  int ans = -inf;
  int ans2 = -inf;
  int pos=l;
  int nl;
  
  for(int i=l; i<r-2*(b-p-1); i++){

    nl = i+2;
    if(p==b-1){
      bst[p+1][nl%z][r%z] = 0;
    }
    else if(bst[p+1][nl%z][r%z]==-inf){
      bst[p+1][nl%z][r%z]= best(p+1,nl,r);
    }
    ans = max(ans,bst[p+1][nl%z][r%z]-(rou[i%z]+rou[(i+1)%z])*balls[p]);
    if(ans!=ans2){
      pos=i;
      ans2=ans;
    }
  }
  for(int i=pos; i>l; i--){
    bst[p][i%z][r%z]=ans;
  }


  return ans;
}

int main(){ _
     
  cin >> z >> b;
  int ans = -inf;
  balls.resize(126);
  rou.resize(251);
  bst.resize(126, vector<vector<int>>(251, vector<int>(251,-inf)));

  while(z>0){
    ans = -inf;
    bst.clear();
    /*for(int i = 0; i<b+1; i++){
      for(int j=0; j<z+1;j++){
        for(int k=0; k<z+1;k++){
          bst[i][j][k]=-inf;
        }
      }
    }*/
    bst.resize(b+1, vector<vector<int>>(z+1, vector<int>(z+1,-inf)));

    for(int i = 0; i<z; i++){
      cin >> rou[i];
    }
    for(int i =0; i<b; i++){
      cin >> balls[i];
    }
    
    for(int i = 1; i<z+1; i++){
      bst[1][(i+2)%z][i-1] = best(1,i+2, i-1+z);
      ans = max(ans, bst[1][(i+2)%z][i-1]-(rou[i%z]+rou[(i+1)%z])*balls[0]);
    }
    cout << ans << endl;

    cin >> z >> b;
  }
  
  return(0);
}
