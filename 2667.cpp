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
   
  string a;
  cin >> a;

  int sum = 0;

  for(int i=0; i<a.size();i++){
    sum+= int(a[i] - '0');
  }
  cout << sum%3 << endl;
  return(0);
}
