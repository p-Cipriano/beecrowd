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

vector<vector<int>>posarranj;
vector<vector<int>>totarranj;


void upposarranj(){
  posarranj.resize(pow(3,5));
  int i = 0;
  for(int p5=1;p5<=3;p5++){
    for(int p4=1;p4<=3;p4++){
      for(int p3=1;p3<=3;p3++){
        for(int p2=1;p2<=3;p2++){
          for(int p1=1;p1<=3;p1++){
            posarranj[i].pb(p1);
            posarranj[i].pb(p2);
            posarranj[i].pb(p3);
            posarranj[i].pb(p4);
            posarranj[i].pb(p5);
            i++;
          }
        }
      }
    }
  }
}
void uptotarranj(){
  totarranj.resize(pow(4,5));
  int i = 0;
  for(int p5=1;p5<=4;p5++){
    for(int p4=1;p4<=4;p4++){
      for(int p3=1;p3<=4;p3++){
        for(int p2=1;p2<=4;p2++){
          for(int p1=1;p1<=4;p1++){
            totarranj[i].pb(p1);
            totarranj[i].pb(p2);
            totarranj[i].pb(p3);
            totarranj[i].pb(p4);
            totarranj[i].pb(p5);
            i++;
          }
        }
      }
    }
  }
}


int main(){ _
     
  int t;
  int items;
  size_t aux;

  int currenpos=0;
  int sum=0;
  int posblt=1;


  vector<string> rep;
  vector<string> num;
  vector<vector<vector<ll>>> pos;

  string lix;

  vector<ll> auxvec;

  vector<int>perm;

  cin >> t;

  getline(cin,lix);

  upposarranj();
  uptotarranj();

  for(int k=0;k<t;k++){
    
    perm.clear();
    pos.clear();
    rep.clear();
    num.clear();
    
    rep.resize(6);
    num.resize(6);
    pos.resize(6,vector<vector<ll>>(0, vector<ll>(0)));
    
    items = 0;
    posblt=1;

    for(int i=0;i<6;i++){
      getline(cin,rep[i]);
      
      if(i==0){
        aux = rep[0].find_first_of("12345");
        while(aux!=string::npos){
          items++;
          rep[0].replace(aux+1,0, " ");
          aux = rep[0].find_first_of("12345",aux+1);
        }
      }
      else if(rep[i].substr(0,2)=="TP"){
        num[i] = rep[i].substr(2);
        num.resize(i+1);
        rep[i].resize(2);
        rep.resize(i+1);

        for(int j=0;j<pow(4,items);j++){
          auxvec.clear();
          currenpos=0;
          sum=0;
          for(int l=0;l<items;l++){
            if(currenpos+totarranj[j][l]-1>=num[i].size()-(items-1-l) || (num[i][currenpos]=='0'&& totarranj[j][l]>1)){
              sum=-1;
              break;
            }
            auxvec.pb(stoll(num[i].substr(currenpos,totarranj[j][l])));
            sum+=auxvec[auxvec.size()-1];
            currenpos+=totarranj[j][l];
            if(currenpos>=num[i].size()){
              sum=-1;
              break;
            }
          }
          if(sum!=-1 && num[i].size()-currenpos<7){
            if(sum==stoll(num[i].substr(currenpos)) && (num[i][currenpos]!='0' || currenpos==num[i].size()-1)){
              auxvec.pb(stoll(num[i].substr(currenpos)));
              pos[i].pb(auxvec);
            }
          }
        }
        posblt*=pos[i].size();
        break;
      }
      else{
        aux = rep[i].find_first_of("1234567890");
        num[i] = rep[i].substr(aux);
        rep[i].resize(aux);
        sum=0;
        currenpos=0;

        for(int j=0;j<pow(3,items);j++){
          auxvec.clear();
          currenpos=0;
          sum=0;
          for(int l=0;l<items;l++){
            if(currenpos+posarranj[j][l]-1>=num[i].size()-(items-1-l) || (num[i][currenpos]=='0'&&posarranj[j][l]>1)){
              sum=-1;
              break;
            }
            auxvec.pb(stoll(num[i].substr(currenpos,posarranj[j][l])));
            sum+=auxvec[auxvec.size()-1];
            currenpos+=posarranj[j][l];
            if(currenpos>=num[i].size()){
              sum=-1;
              break;
            }
          }
          
          if(sum!=-1 && num[i].size()-currenpos<7){
            if(sum==stoll(num[i].substr(currenpos)) && (num[i][currenpos]!='0' || currenpos==num[i].size()-1)){
              auxvec.pb(stoll(num[i].substr(currenpos)));
              pos[i].pb(auxvec);
            }
          }
        }
        posblt*=pos[i].size();
      }
    }
    perm.resize(rep.size(),0);

    sum=0;

    int permp = 1;

    for(int i = 0;i<posblt;i++){
      for(int j=0;j<items+1;j++){
        sum=0;
        for(int l=1;l<rep.size()-1;l++){
          sum+=pos[l][perm[l]][j];
        }
        if(sum!=pos[rep.size()-1][perm[perm.size()-1]][j]){
          sum=-1;
          break;
        }
      }
      if(sum!=-1){
        break;
      }
      else{
        permp=1;
        while(1){
          if(perm[permp]==pos[permp].size()-1){
            perm[permp]=0;
            permp++;
            if(permp>=perm.size())
              break;
          }
          else{
            perm[permp]++;
            break;
          }
        }
      }
    }
    if(sum==-1){
      cout << "end" << endl;
      return -1;
    }

    for(int i=0;i<rep.size();i++){
      cout << rep[i];
      if(i!=0){
        for(int j=0;j<items+1;j++){
          cout << " " << pos[i][perm[i]][j];
        }
      }
      cout << endl;
    }
  }

  return(0);
}
