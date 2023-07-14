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
     
  int n,k;

  cin >> n >> k;

  vector<vector<int>>h;
  map<char,int> dic;
  dic['A']=1;
  dic['2']=2;
  dic['3']=3;
  dic['4']=4;
  dic['5']=5;
  dic['6']=6;
  dic['7']=7;
  dic['8']=8;
  dic['9']=9;
  dic['D']=10;
  dic['Q']=11;
  dic['J']=12;
  dic['K']=13;
  h.resize(n+1);

  char c;
  int winner = 0;
  int todis=0;
  int towin=0;

  for(int i=1;i<=n;i++){
    h[i].resize(14,0);
    for(int j=0;j<4;j++){
      cin >> c;
      h[i][dic[c]]++;
      if(h[i][dic[c]]==4 && !winner && i!=k){
         winner=i;
      }
    }
  }
  

  if(winner!=0){
    cout << winner << endl;
    return 0;
  }

  h[k][0] = -1;

  while(1){
    todis=0;
    if(h[k][0]==1){
      h[k][0]=0;
      k++;
      if(k==n+1)
        k=1;
      h[k][0]=-1;
    }
    else{
      if(h[k][0]==-1)
         h[k][0]=1;
      for(int i=1;i<14;i++){
        if(todis!=0 && h[k][i]<h[k][todis] && h[k][i]>0)
          todis=i;
        else if(todis==0 && h[k][i]>0)
          todis=i;
      }
      h[k][todis]--;
      k++;
      if(k==n+1){
        k=1;
      }
      h[k][todis]++;
      if(h[k][todis]==4){
        winner = k;
        break;
      }
    }
  }
  cout << winner << endl;
  
  return(0);
}
