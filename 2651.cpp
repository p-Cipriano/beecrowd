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

int main(){ _

  string z = "zelda";
  string Z = "ZELDA";

  int ans=0;

  string in;
  cin >> in;

  for(int i = 0; i < in.size(); i++){
    if(in[i]==z[ans] || in[i]==Z[ans])
      ans++;
    else
      ans=0;
    if(ans==5){
      cout << "Link Bolado";
      break;
    }
    if(i==in.size()-1)
      cout << "Link Tranquilo";
  }
     
  
  return(0);
}
