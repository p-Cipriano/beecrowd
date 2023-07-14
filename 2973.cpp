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
     
  int n,c,t;
  cin >> n >> c >> t;

  vector<int>Fx;
  Fx.resize(n+1);


  int mx=0;
  int lans=0;
  int hans=0;
  int aux =0;
  int pn=0;
  int lp=0;

  Fx[0]=0;

  for(int i=1;i<n+1;i++){
    cin>>Fx[i];
    mx=max(mx,Fx[i]);
    if(i>0)
      Fx[i]+=Fx[i-1];
  }

  lans=max(ceil((double)mx/t), ceil((double)Fx[n]/(c*t)));
  hans=ceil((double)n/c)*ceil((double)mx/t);
  
  aux=(lans+hans)/2;

  while(1){
    pn=1;
    lp=0;
    //cout << lans << "-" << hans << endl;
    for(int i=1;i<n+1;i++){
      if(Fx[i]-Fx[lp]>t*aux){
        lp=i-1;
        pn++;
        if(pn>c)
          break;
      }
    }
    if(pn>c){
      lans=aux+1;
      aux = (lans+hans)/2;
      if(hans==lans)
        break;

    }
    else{
      //cout << aux << endl;
      hans=aux;
      aux =(lans+hans)/2;
      //cout << aux << endl;
      if(aux==hans)
        break;
    }
  }

  cout << hans << endl;

  return(0);
}
