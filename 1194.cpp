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

string ans(string pres, map<char, int> in, int lb, int ub, int j){
    
    if(lb+1 >= ub)
      return pres.substr(j,1);


    int ub1 = in[pres[j]];
    string subans1;
    string subans2;
    if(lb<ub1)
      subans1 = ans(pres,in,lb,ub1,j+1);
    if(ub1+1<ub)
      subans2 = ans(pres,in,ub1+1,ub,j+1+ub1-lb);
    return subans1+subans2+pres.substr(j,1);
}
map<char, int> in;
 
int main(){ _
   int c;
   string pres;
   string ins;
   int size;

   cin >> c;
   for(int i=0;i<c;i++){
      
     cin >> size >> pres >> ins;
     in.clear();

     for(int j=0;j<size;j++){
       in[ins[j]] = j;
     }

     cout << ans(pres, in, 0, size, 0) << endl;
   }
   
   return(0);
}
