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
  

int m,t;

vector<int>tx;
vector<int>pat;

map<string,int> k;

void defk(){

  k["A"] = 0;
  
  k["A#"] = 1;  
  k["Bb"] = 1;
  
  k["B"] = 2; 
  k["Cb"] = 2;
  
  k["B#"] = 3;
  k["C"] = 3;
  
  k["C#"] = 4;  
  k["Db"] = 4;

  k["D"] = 5;
  
  k["D#"] = 6;  
  k["Eb"] = 6;

  k["E"] = 7;
  k["Fb"] = 7;
  
  k["E#"] = 8;
  k["F"] = 8;
  
  k["F#"] = 9;  
  k["Gb"] = 9;

  k["G"] = 10;
  
  k["G#"] = 11;  
  k["Ab"] = 11;
}

bool pattern(){

    int len = 0;
 
    vector<int> skp;
    skp.resize(t);
    skp[0] = 0;

    for(int i = 1; i < t;){

      if(pat[i] == pat[len]){
        len++;
        skp[i] = len;
        i++;
      }
      else if (len != 0) len = skp[len - 1];
      else skp[i++] = 0;
    
    }
    int i = 0;
    int j = 0;

    while(i<m) {
        
        while(pat[j] == tx[i]){
            j++;
            i++;
            //cout << i
            if(j==t || i==m) break;
        }

        if(j == t) return(1);
        if(i == m) return(0);

        if (j != 0) j = skp[j - 1];
        else i++;
    }
    return(0);
}

int main(){ _

  defk();

  cin >> m >> t;

  while(m){
    
    tx.clear();
    pat.clear();

    string aux;

    for(int i = 0; i < m; i++){
      cin >> aux;
      aux.erase(remove_if(aux.begin(), aux.end(), ::isspace), aux.end());
      tx.pb(k[aux]);
    }
    for(int i = 0; i < t; i++){
      cin >> aux;
      aux.erase(remove_if(aux.begin(), aux.end(), ::isspace), aux.end());
      pat.pb(k[aux]);
    }
    
    for(int i = 0; i < 12; i++){
      if(pattern()){
        cout << "S" << endl;
        break;
      }
      if(i==11){
        cout << "N" << endl;
        break;
      }

      for(int j = 0; j < t; j++){
        pat[j]++;
        pat[j]%=12;
      }
    }
    cin >> m >> t;
  }


  return(0);
}
