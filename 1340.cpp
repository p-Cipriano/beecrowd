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
   int ans[3] = {1,1,1}; 
   int n;
   int com;
   int el;

   stack<int> s;
   queue<int> q;
   priority_queue<int> pq;

   while(cin >> n){
      ans[0] = 1;
      ans[1] = 1;
      ans[2] = 1;
      while(!s.empty()){
        s.pop();
        q.pop();
        pq.pop();
      }
      for(int i = 0; i<n; i++){
        cin >> com;
        if(com == 1){
          cin >> el;
          s.push(el);
          q.push(el);
          pq.push(el);
        }
        else if(com == 2){
          cin >> el;
          if(s.top()!=el)
            ans[0] = 0;
          if(q.front()!=el)
            ans[1] = 0;
          if(pq.top()!=el)
            ans[2] = 0;
          s.pop();
          q.pop();
          pq.pop();
        }
      }
      if(ans[0]+ans[1]+ans[2] == 0)
        cout << "impossible" << endl;
      else if(ans[0]+ans[1]+ans[2] > 1)
        cout << "not sure" << endl;
      else if(ans[0]==1)
        cout << "stack" << endl;
      else if(ans[1] == 1)
        cout << "queue" << endl;
      else
        cout << "priority queue" << endl;
   }
   
   return(0);
}
