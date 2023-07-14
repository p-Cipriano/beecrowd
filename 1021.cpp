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
  float n;
  cin >> n;

  int k = 100*n;

  cout << "NOTAS:" << endl;
  cout << k/10000 << " nota(s) de R$ 100.00" << endl;
  k = k%10000;
  cout << k/5000 << " nota(s) de R$ 50.00" << endl;
  k = k%5000;
  cout << k/2000 << " nota(s) de R$ 20.00" << endl;
  k = k%2000;
  cout << k/1000 << " nota(s) de R$ 10.00" << endl;
  k = k%1000;
  cout << k/500 << " nota(s) de R$ 5.00" << endl;
  k = k%500;
  cout << k/200 << " nota(s) de R$ 2.00" << endl;
  k = k%200;

  cout << "MOEDAS:" << endl;
  cout << k/100 << " moeda(s) de R$ 1.00" << endl;
  k = k%100;
  cout << k/50 << " moeda(s) de R$ 0.50" << endl;
  k = k%50;
  cout << k/25 << " moeda(s) de R$ 0.25" << endl;
  k = k%25;
  cout << k/10 << " moeda(s) de R$ 0.10" << endl;
  k = k%10;
  cout << k/5 << " moeda(s) de R$ 0.05" << endl;
  k = k%5;
  cout << k << " moeda(s) de R$ 0.01" << endl;
  
  return(0);
}
