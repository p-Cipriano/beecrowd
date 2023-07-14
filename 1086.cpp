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


  int n,m;
  int l;
  int k;
  int aux;
  vector<int> pl;
  vector<int> h;
  vector<int> v;

  int vans=0;
  int hans=0;
  int rn,cn;
  int rncp, cncp;

  cin >> n >> m;

  while(n!=0){
    
    cin >> l;
    cin >> k;
    
    rn = m*100/l;
    rncp = rn;
    cn = n*100/l;
    cncp=cn;

    if((float)m*100/l!=m*100/l){
      rn = inf;
    }
    if((float)n*100/l!=n*100/l){
      cn = inf;
    }
    
    hans=2*rn;
    vans=2*cn;
    
    pl.clear();
    h.clear();
    v.clear();
    h.resize(n/2+1,0);
    v.resize(m/2+1,0);
    pl.resize(k);

    for(int i = 0; i<k; i++){
      cin >> aux;
      //cout << aux << endl;
      if(aux <= n){
        if(aux < ceil((float)n/2)){
          if(h[aux]<0){
            rn--;
          }
          h[aux]++;
        }
        else if(aux==n/2 && n%2==0){
          if(h[aux]>0){
            rn--;
            h[aux]--;
          }
          else{
            h[aux]++;
          }
        }
        else if(aux < n){
          if(h[n-aux]>0){
            rn--;
          }
          h[n-aux]--;
        }
        else if(hans>rncp){
          rn--;
          hans--;
        }
      }
      if(aux <= m){
        if(aux < ceil((float)m/2)){
          if(v[aux]<0){
            cn--;
          }
          v[aux]++;
        }
        else if(aux==m/2 && m%2==0){
          if(v[aux]>0){
            cn--;
            v[aux]--;
          }
          else{
            v[aux]++;
          }
        }
        else if(aux < m){
          if(v[m-aux]>0){
            cn--;
          }
          v[m-aux]--;
        }
        else if(vans>cncp){
          cn--;
          vans--;
        }
      }

    }

    if(rn>0)
      hans = inf;
    if(cn>0)
      vans = inf;

    if(rn<=0 || cn<=0)
      cout << min(vans,hans) << endl;
    else
      cout << "impossivel" << endl;


    cin >> n >> m;
  }
     
  
  return(0);
}
