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
  int n;
  int pac;
  int qt;
  int w;
  int g;
  int can;
  vector<ii> items;
  int table[51][101][3];

  cin >> n;

  for(int i=0; i<n; i++){
    cin >> pac;
    items.resize(pac);

    for(int j = 0; j< pac; j++){
      cin >> qt >> w;
      items[j] = make_pair(qt,w);
      
    }

    cin >> g;
    cin >> can;
    
    for(int j = 0; j < pac+1; j++){
      for(int k = 0; k < g+1; k++){
        if(k==0 || j==0){
          table[j][k][0] = 0;
          table[j][k][1] = 0;
          table[j][k][2] = 0;
        }
        else if(items[j-1].s <= k && table[j-1][k][0] <= table[j-1][k-items[j-1].s][0]+items[j-1].f){
          table[j][k][0] = table[j-1][k-items[j-1].s][0]+items[j-1].f;
          table[j][k][1] = table[j-1][k-items[j-1].s][1] + items[j-1].s;
          table[j][k][2] = table[j-1][k-items[j-1].s][2] + 1; 
        }
        else{
          table[j][k][0] = table[j-1][k][0];
          table[j][k][1] = table[j-1][k][1];
          table[j][k][2] = table[j-1][k][2];
        }
        //cout << table[j][k][0] << " ";
      }
      //cout << endl;
    }
    
    if(table[pac][g][0]>=can)
      cout << "Missao completada com sucesso" << endl;
    else
      cout << "Falha na missao" << endl;

    //cout << table[pac][50][0] << " brinquedos " << endl;
    //cout << "Peso: " << table[pac][50][1] << " kg " << endl;
    //cout << "sobra(m) " << pac-table[pac][50][2] << " pacote(s) " << endl;
    //cout << endl;
    
  }
  
  return(0);
}
