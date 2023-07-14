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
vector<vector<int>> board; 
vector<vector<int>>best;
int play(int i, int j){
    int ans =0;
   
    if(j<board[0].size()-2 && i<board.size()-2 && board[i+1][j+1]==2 && board[i+2][j+2]==0){
      board[i+2][j+2]=1;
      board[i+1][j+1]=0;
      board[i][j]=0;
      ans = max(ans,play(i+2,j+2)+1);
      board[i+2][j+2]=0;
      board[i+1][j+1]=2;
      board[i][j]=1;
    }
    if(j>1 && i<board.size()-2 && board[i+1][j-1]==2 && board[i+2][j-2]==0){
      board[i+2][j-2]=1;
      board[i+1][j-1]=0;
      board[i][j]=0;
      ans = max(ans,play(i+2,j-2)+1);
      board[i+2][j-2]=0;
      board[i+1][j-1]=2;
      board[i][j]=1;
    }
    if(j>1 && i>1 && board[i-1][j-1]==2 && board[i-2][j-2]==0){
      board[i-2][j-2]=1;
      board[i-1][j-1]=0;
      board[i][j]=0;
      ans = max(ans,play(i-2,j-2)+1);
      board[i-2][j-2]=0;
      board[i-1][j-1]=2;
      board[i][j]=1;
    }
    if(j<board[0].size()-2 && i>1 && board[i-1][j+1]==2 && board[i-2][j+2]==0){
      board[i-2][j+2]=1;
      board[i-1][j+1]=0;
      board[i][j]=0;
      ans = max(ans,play(i-2,j+2)+1);
      board[i-2][j+2]=0;
      board[i-1][j+1]=2;
      board[i][j]=1;
    }
    best[i][j]=ans;
    return ans;
}

int main(){ _
  
  int n,m;
  vector<ii> ones;
  int ans = 0;

  cin >> n >> m;

  while(n!=0 && m!=0){
    ans = 0;
    board.clear();
    board.resize(n,vector<int>(m));
    
    best.clear();
    best.resize(n,vector<int>(m));
    
    ones.clear();
    
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if((j+i)%2==0){
          cin >> board[i][j];
          best[i][j]=0;
          if(board[i][j]==1)
            ones.pb(make_pair(i,j));
        }
      }
    }
    
    for(auto p : ones){
      ans = max(play(p.f,p.s),ans);
    }

    cout << ans << endl;

    cin >> n >> m;     
  }
  return(0);
}
