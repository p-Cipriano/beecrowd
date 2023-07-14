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

class cell{

  public:

  char c;
  vector<cell*>next;

  cell(char c_){
    c = c_;
  }
};

int main(){ _

  int n;
  cin >> n;

  while(n){
    
    cell* root = new cell('c');

    int ans = 1;

    for(int i = 0; i< n; i++){
      string pa;
      cin >> pa;
      cell* aux = root;

      if(!ans) continue;
      
      int flag = 1;

      for(int j = 0; j < pa.size(); j++){

        if(aux->next.size()==0 && flag==0){
          ans = 0;
          continue;
        }

        flag = 1;

        for(auto& k : aux->next){
          if(k->c == pa[j]){
            aux = k;
            flag = 0;
            break;
          }
        }
        if(flag){
          cell* aux2 = new cell(pa[j]);
          aux->next.pb(aux2);
          aux = aux2;
        }
      }

      if(!flag)
        ans = 0;
    }

    if(ans) cout << "Conjunto Bom" << endl;
    else cout << "Conjunto Ruim" << endl;

    cin >> n;
  } 
  
  return(0);
}
