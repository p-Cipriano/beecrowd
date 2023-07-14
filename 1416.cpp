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
        
  int t,p;
  int lb,ub;
  
  int tri;
  int aux;
  char mint[100];
  vector<vector<int>>score;
  
  scanf("%d%d",&t,&p);
  while(t!=0){
    score.clear();
    score.resize(t);
    lb=1;
    ub=inf;

    for(int i=0;i<t;i++){
      score[i].resize(5,0);
      score[i][4]=i;
      //printf("\n%d\n", i);
      for(int j=0;j<p;j++){
        scanf("%d/%s", &tri, &mint);
        //printf("%d %s\n", tri, mint);
        if(mint[0]!='-'){
          score[i][0]++;
          sscanf(mint,"%d", &aux);
          score[i][2]+=aux;
          score[i][3]+=tri-1;
        }
      }
      score[i][1] = score[i][2]+20*score[i][3];
    }


    sort(score.begin(),score.end(),[](const std::vector<int>& a, const std::vector<int>& b) {
      if(a[0]==b[0]){
        return a[1] < b[1];
      }
      return a[0] > b[0];
    });

    /*for(int i =0;i<score.size();i++){
      printf("%d-%d\n", score[i][0], score[i][1]);
    }
    printf("\n");*/
    //printf("lb=%d\nub=%d\n",lb,ub);

    for(int i=0;i<t-1;i++){
      if(score[i][0]==score[i+1][0]){
        if(score[i][3]!=score[i+1][3] && score[i][1]==score[i+1][1]){
          lb=20;
          ub=20;
          break;
        }
        else if(score[i][3]<score[i+1][3]){
          lb=max(lb,(int)ceil((score[i][2]-score[i+1][2])/(score[i+1][3]-score[i][3]))+1);
          //printf("lb=%d\n",lb);
          //printf("%d\n", (int)ceil(((double)score[i][2]-score[i+1][2])/(score[i+1][3]-score[i][3]))+1);
        }
        else if(score[i][3]>score[i+1][3]){
          aux= (score[i][2]-score[i+1][2])/(score[i+1][3]-score[i][3]);
          if(aux!=((double)score[i][2]-score[i+1][2])/(score[i+1][3]-score[i][3]))
            ub=min(ub,aux);
          else
            ub=min(ub,aux-1);
          //printf("ub=%d\n",ub);
        }
      }
    }

    if(ub==inf)
      printf("%d *\n", lb);
    else
      printf("%d %d\n", lb, ub);
    
    scanf("%d%d",&t,&p);
  }
  
  return(0);
}
