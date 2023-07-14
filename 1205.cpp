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

/*int ft(int c){
  int ans = 1;
  for(int i=2; i<=c;i++)
    ans*=i;
  return ans;
}*/

int main(){ _
     

  int n,m,k;
  double p;
  int a;
  vector<vector<int>> adj;
  vector<int> cost;
  vector<int> dist;
  queue<int> tovisit;
  int u,v,aux;
  int start, end;
  //double ans;
  //double lans;
  //double daux;

  cout.precision(3);

  while(cin>>n>>m>>k>>p){

    adj.clear();
    adj.resize(n);
    cost.clear();
    cost.resize(n+1,0);
    dist.clear();
    dist.resize(n+1,inf);

    for(int i=0;i<m;i++){
      cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    
    cin >> a;
    for(int i=0;i<a;i++){
      cin >> aux;
      cost[aux]++;
    }
    cin >> start >> end;

    dist[start] = 0;

    tovisit.push(start);

    do{
      aux = tovisit.front();
      tovisit.pop();
      for(auto i:adj[aux]){
        if(dist[aux]+cost[aux]<dist[i]){
          dist[i] = dist[aux]+cost[aux];
          tovisit.push(i);
        }
      }
    }while(!tovisit.empty());

    

    if(dist[end]+cost[end]<=k){
      /*ans=0;
      //cout << cost[end] << "cost end and dist" << dist
      lans = ft(dist[end]+cost[end]-1);
      daux=pow(p,dist[end]+cost[end])/lans;

      for(int i = 0;i <= k-dist[end]-cost[end];i++){
        if(i>0)
          lans *= (dist[end]+cost[end]+i-1)/i;
        ans += pow(1-p,i)*lans;
      }
      ans*=daux;*/
      cout << fixed << setprecision(3) << (double)pow(p,dist[end]+cost[end]) << endl;
    }
    else{
      cout << "0.000" << endl;
    }
  }
  
  return(0);
}

