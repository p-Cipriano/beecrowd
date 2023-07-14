#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

const int inf=0x3f3f3f3f;
const long long linf=0x3f3f3f3f3f3f3f3fll;
 
vector<ii>room;
vector<double>cost;
priority_queue <double>gain;

int main(){ _
     
  int n,k,v;
  double sum;
  while(cin>>n>>k>>v){
    room.clear();
    cost.clear();
    sum = 0;

    cost.resize(n);
    room.resize(n, make_pair(0,0));
    for(int i=0; i<n; i++){
      cin >> room[i].f >> room[i].s;
      cost[i]=(double)room[i].f/(double)v;
      gain.push(-(double)room[i].f/(double)(v+room[i].s)+cost[i]);
      sum+= cost[i];
      //cout << cost[i] << " ";
    }
    //cout << endl;
  
    for(int i=0;i<min(k,n);i++){
      //cout << gain.top() << " ";
      sum-=gain.top();
      gain.pop();
    }
    while(!gain.empty())
      gain.pop();
    //cout << endl;
    cout << fixed << setprecision(4) << sum << endl;
  }
  return(0);
}
