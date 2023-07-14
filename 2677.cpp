#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mk make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

const int inf=0x3f3f3f3f;
const long long linf=0x3f3f3f3f3f3f3f3fll;

int n;
vector<int> v;
vector<vector<ii>> best;
vector<int> f;
int ans = -inf;


ii bst(int turn, int l, int r, int score){

  if(r==l){
    
    if(turn && v[r]==0){
      ans = max(ans, score);
      return mk(0,1);
    }
    else if(v[r]==0){
      ans = max(ans, score+1);
      return mk(1,0);
    }
    else{
      ans = max(ans,score);
      return mk(0,0);
    }
  }

  int nt = (turn+1)%2;
  int lg = v[l]==0;
  int rg = v[r]==0;

  if(best[l+1][r].f == -inf /*&& ans < score+f[r]-f[l]+(!turn && lg)*/){
    best[l+1][r] = bst(nt,l+1,r, score+(!turn && lg));
  }

  if(best[l][r-1].f == -inf /*&& ans < score+f[r-1]-f[l]+(!turn && rg)+lg*/){
    best[l][r-1] = bst(nt,l,r-1, score+(!turn && rg));
  }
  

  ii ansl = best[l+1][r];
  ii ansr = best[l][r-1];

  if(ansl.f==-inf && ansr.f==-inf){
    return mk(-inf,-inf);
  }

  if(v[l]==0){
    if(turn)
      ansl.s++;
    else
      ansl.f++;
  }

  if(v[r]==0){
    if(turn)
      ansr.s++;
    else
      ansr.f++;
  }

  if(turn){
    if(ansl.s>ansr.s)
      return ansl;
    else
      return ansr;
  }
  else{
    if(ansl.f>ansr.f){
      return ansl;
    }
    else 
      return ansr;
  }
}

int main(){ _
     
  cin>>n;
  v.resize(1001);
  f.resize(1001);
  best.resize(1001, vector<ii>(1001));

  while(n>0){

    ans = -inf;
    int aux;
    
    for(int j=0; j<2*n+1; j++){
      for(int k=0; k<2*n+1; k++){
        best[j][k] = mk(-inf,-inf);
      }
    }

    for(int i = 0; i<2*n; i++){
      cin >> aux;
      v[i]=aux%2;
      
      if(i==0)
        f[i] = (aux+1)%2;
      else
        f[i] = f[i-1]+(aux+1)%2;
      
    }
    ii t = bst(0,0,2*n-1,0);
    cout << t.f << endl;


    cin>>n;
  }
  
  return(0);
}
