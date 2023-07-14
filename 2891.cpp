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

class point{
  public:

  int x;
  int y;

  point(const point &k){
    x = k.x;
    y = k.y;
  }
  point operator+(point const& p){
    return point(x+p.x, y+p.y);
  }
  
  point operator-(point const& p){
    return point(x-p.x, y-p.y);
  }

  bool operator<(point const& p){
    return x<p.x;
  }
  bool operator==(point const& p){
    return x==p.x && y == p.y;
  }
  point(int x_, int y_){
    x = x_;
    y = y_;
  }
  point(){
    x = inf; y = inf;
  }
};

point fir = point(0,0);
deque<point> order;
vector<point> p;
vector<vector<int>>pos;

int det(point a, point b){
  return a.x*b.y-a.y*b.x;
}

int func(point v, point r, point l, point oppo){
  point u1 = r - v;
  point u2 = l - v;
  
  point v1 = r - oppo;
  point v2 = l - oppo;

  return (abs(det(u1,u2))+abs(det(v1,v2)))/2;
}

bool quad(point v, point r, point l, point oppo){
  if(det(r-v, l-v)<=0) return false;
  if(det(r-v,oppo-v)<= 0) return false;
  if(det(l-v,oppo-v)>= 0) return false;
  if(det(l-r,oppo-r)>= 0) return false;
  return true;
}

int area(int ex){
  int ans = 0;
  for(int i = 0; i<4; i++){
    point v1 = p[pos[ex][i]];
    for(int j = i+1;j%5!=i;j++){
      point lef = p[pos[ex][j%5]];
      for(int k = j+1; k%5!=j%5; k++){
        if(k%5==i) continue;
        point right = p[pos[ex][k%5]];
        for(int l = k+1; l%5!=k%5; l++){
          if(l%5==i || l%5==j%5) continue;
          point oppo = p[pos[ex][l%5]];
          //cout << ex << " " << i << " " << j << " " << k << " " << l << endl; 
          if(quad(v1,lef,right,oppo))
            ans = max(ans, func(v1,lef,right, oppo));
        }
      }
    }
  }
  return ans;
}

int main(){ _
     
  point aux = point(0,0);

  p.resize(5);

  pos.pb({1,2,3,4});
  pos.pb({0,2,3,4});
  pos.pb({0,1,3,4});
  pos.pb({0,1,2,4});
  pos.pb({0,1,2,3});

  int ans = 0;

  int it = 0;
  for(int i = 0; i<5; i++){
    cin >> p[i].x >> p[i].y;
    it+=p[i].x + p[i].y;
  }
  while(it){

    fir = point(inf,inf);

    order.clear();

    /*for(int i = 0; i<5; i++){
      if(p[i].y<fir.y){
        fir = p[i];
      }
      else if(p[i].y==fir.y && p[i].x<fir.x){
        fir = p[i];
      }
    }

    order.pb(point(fir));

    sort(p.begin(), p.end(), [](auto& a, auto& b){
      if(a==fir)
        return true;
      else if(b==fir)
        return false;

      return det(a - fir, b - fir) > 0;
    });*/

    ans = 0;
    
    for(int i = 0; i < 5; i++){
      ans = max(ans, area(i));
    }
    
    cout << ans << endl;
    
    it = 0;

   // break;

    for(int i = 0; i<5; i++){
      cin >> p[i].x >> p[i].y;
      it+=p[i].x + p[i].y;
    }
    
  }

  return(0);
}
