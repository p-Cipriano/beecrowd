#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

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

int r,c,k; 
vector<vector<int>> rom;
vector<vector<int>> fx;
vector<vector<int>> gx;
int ans;

int main(){ _
     
  cin >> r >> c >> k;
  char aux;
  int cans;
  rom.resize(300, vector<int>(300));
  fx = rom;
  gx = fx;

  while(r){

    ans = inf;

    for(int i =0; i<r; i++){
      for(int j = 0; j<c; j++){
        cin >> aux;
        if(aux=='.')
          rom[i][j] = 1;
        else
          rom[i][j] = 0;

          
        fx[i][j]=rom[i][j];
        if(j>0)
          fx[i][j]+=fx[i][j-1];

        if(fx[i][j]>=k && j+1<ans)
          ans=min(ans,j+1);
        
        gx[i][j]=rom[i][j];
        if(i>0)
          gx[i][j]+=gx[i-1][j];

        if(gx[i][j]>=k && i+1<ans)
          ans=min(ans,i+1);
      }
    }
    
    for(int i=0; i<r; i++){
        
        for(int a = 1; a<=min(ans,r-i); a++){
          
         cans=0;
         for(int d = 0, b = 0; b< c; b++){
            cans+=gx[i+a-1][b]-gx[i][b]+rom[i][b];

            while(d<c && cans-(gx[i+a-1][d]-gx[i][d]+rom[i][d])>=k){
              cans-=gx[i+a-1][d]-gx[i][d]+rom[i][d];
              d++;
            }
            
            if(cans>=k && ans>a*(b-d+1)){
              ans=a*(b-d+1);
              if(ans==k)
                break;
            }
          }
          if(ans==k)
            break;
        }
        if(ans==k)
          break;
    }

    cout << ans << endl;

    cin >> r >> c >> k;
  }


  return(0);
}
