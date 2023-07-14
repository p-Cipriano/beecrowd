#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define s second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int inf=0x3f3f3f3f;
const long long linf=0x3f3f3f3f3f3f3f3fll;


vector<int> fold1(vector<int> f, int w){
    vector<int> aux;
    aux.clear();
    aux.resize(f.size()-w);
    for(int i=0; i<aux.size();i++){
      aux[i] = f[i];
      if(2*aux.size()-i-1 < f.size()){
        aux[i]+= f[2*aux.size()-i-1];
      }
    }
    return aux;
}
vector<int> fold2(vector<int> f, int w){
    vector<int> aux;
    aux.clear();
    aux.resize(f.size()-w);
    int mir = f.size()-2*aux.size();
    for(int i=0; i<aux.size();i++){
      aux[i] = f[f.size()-i-1];
      if(mir+i >= 0){
        aux[i]+= f[mir+i];
      }
    }
    return aux;
}

char recursion(vector<int> f, vector<int> ans){
  char c = 'N';
  bool flag=0;
    /*cout << "f = ";
    for(int i = 0; i<f.size(); i++){
    cout << f[i] << " ";
  }
  cout << endl;*/
  if(f.size()==ans.size()){
    for(int i=0;i<f.size();i++){
      if(f[i]!=ans[i]){
        flag = 1;
        break;
      }
    }
    if(flag==0)
      return 'S';
    for(int i=0;i<f.size();i++){
      if(f[f.size()-1-i]!=ans[i])
        return 'N';
    }

    return 'S';
  }
  for(int i=1;i<=min(f.size()-ans.size(), f.size()/2);i++){
    c = recursion(fold1(f,i), ans);
    if(c=='S')
      break;
    c = recursion(fold2(f,i),ans);
    if(c=='S')
      break;
  }
  return c;
}

int main(){ _
        
    int n,m;
  char c = 'N';
  vector<int> f;
  vector<int> ans;

  while(cin >> n){
    c='N';
    f.clear();
    f.resize(n);
    ans.clear();
    for(int i = 0; i<n; i++){
      cin >> f[i];
    }
    cin>>m;
    ans.resize(m);

    for(int i=0; i<m; i++)
      cin >> ans[i];

    cout << recursion(f,ans) << endl;
  }
   
   return(0);
}
