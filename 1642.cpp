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
     
  vector<int> car;
  car.resize(257);
  int ans=0;
  int cans=0;
  int dc = 0;
  deque<char> subs;
  deque<int> deck;
  char c;
  char aux;
  int n;

  scanf("%d", &n);
  while(n){
    dc = 0;
    ans=0;
    cans=0;
    for(int i=0;i<car.size();i++){
      car[i] = 0;
    }
    
    subs.clear();
    deck.clear();
    
    scanf(" %c", &c);
    while(c!=endl){
      /*if(car[(int)c]==0 && dc<n){
        deck.pb(1);
        subs.pb(c);
        car[(int)c] = 1;
        dc++;
        cans++;
      }*/
      if(car[(int)c]>0){
        if(subs.back() == c){
          deck.back()+=1;
          //cout<< "ok1" << endl;
        }
        else{
          subs.pb(c);
          deck.pb(1);
        }
        car[(int)c]++;
        cans++;
      }
      else if(car[(int)c]==0){
        
        while(dc>=n){
          aux = subs[0];
          car[(int)aux]-=deck.front();
          if(car[(int)aux]<0){
            return -1;
          }
          cans-=deck.front();
          deck.pop_front();
          if(car[(int)aux]==0){
            dc--;
          }
          subs.pop_front();
        }
        deck.pb(1);
        dc++;
        car[(int)c]=1;
        subs.pb(c);
        cans++;
      }
      scanf("%c", &c);

      ans=max(ans,cans);
    }
    printf("%d\n",ans);
    scanf("%d", &n);
  }
  return(0);
}
