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

int prime(int n){

  if(n<2)
    return 1;

  for(int i = 2; i<=sqrt(n); i++){
    if(n%i==0)
      return 0;
  }

  return 1;

}

int main(){ _

  int n;
  int dig;

  while(cin >> n){

    if(!prime(n))
      cout << "Nada" << endl;

    else{
      dig = 1;

      while(n>0){
        dig=n%10;
        if(dig!= 2 && dig!=3 && dig!=5 && dig!=7){
          dig=0;
          break;
        }
        n/=10;
      }
      if(!dig)
        cout << "Primo" << endl;
      else
        cout << "Super" << endl;
    }

  }
  
  return(0);
}
