#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")


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

int n,m,q;
vector<int>v;
vector<int>ans;

class treeNode{
  public:

  treeNode* ls;
  treeNode* rs;
  int l,r;
  vector<int> dist;
  int sum = 0;
  int flag;

  treeNode(int l_, int r_){
    l = l_;
    r = r_;
    dist.resize(m,0);
    dist[1] = r-l+1;
    sum = 0;
    flag = 0;
    
    ls = nullptr;
    rs = nullptr;
  }
};

treeNode* buildTree(int l, int r){
  treeNode* ret = new treeNode(l,r);
  if(l < r){
    ret->ls = buildTree(l, (l+r)/2);
    ret->rs = buildTree((l+r)/2+1, r);
  }
  return ret;
}

void print(vector<int> p){
  for(int i = 0; i < p.size(); i++){
    cout << p[i] << " ";
  }
  cout << endl;
}


void update(treeNode* cur, int sum, int a, int b){

  if(cur->r < a || cur->l > b)
    return;

  if(cur->r == cur->l)
    v[cur->r] = (v[cur->r]+sum)%m;

  if(cur->r <= b && cur->l >= a){
    cur->flag = (cur->flag+sum)%m;
    cur->sum += sum;
    return;
  }


  update(cur->ls, sum, a, b);
  update(cur->rs, sum, a, b);


  int rf = cur->flag - cur->rs->flag;
  if(rf<0)
    rf+=m;
  int lf = cur->flag - cur->ls->flag;
  if(lf<0)
    lf+=m;

  for(int i = 0; i<m; i++){
    cur->dist[i] = cur->rs->dist[rf] + cur->ls->dist[lf];
    if(rf==8)
      rf=0;
    else
      rf++;
    if(lf==8)
      lf=0;
    else
      lf++;
  }


  /*for(int i = 0; i<m; i++)
   cur->dist[(i+cur->rs->flag)%m] = cur->rs->dist[(i+cur->flag)%m];
  for(int i = 0; i<m; i++)  
   cur->dist[(i+cur->ls->flag)%m] += cur->ls->dist[(i+cur->flag)%m];*/
}

void prop(treeNode* cur){
  if(cur->sum==0 || cur->l == cur->r)
    return;
  
  update(cur->ls, cur->sum, 0, n-1);
  update(cur->rs, cur->sum, 0, n-1);

  cur->sum = 0;
}

void query(treeNode* cur, int a, int b){

  if(cur->l >= a && cur->r <= b){
    for(int i = 0; i<m; i++){
      ans[(i+cur->flag)%m]+=cur->dist[i];
    }
    return;
  }
  if(cur->l > b || cur->r < a){
    return;
  }

  prop(cur);

  query(cur->ls, a, b);
  query(cur->rs, a, b);

}

void flush(treeNode* cur){
  prop(cur);
  if(cur->r==cur->l) return;
  flush(cur->rs);
  flush(cur->ls);
}


int main(){ _
  
  cin >> n >> q;

  m=9;

  v.resize(n,1);
  ans.resize(m,0);

  treeNode* root = buildTree(0,n-1);

  for(int i = 0; i<q; i++){

      int a,b;
      cin >> a >> b;
      
      query(root,a,b);
      
      int rans = -1;
      int indx = 0;
      for(int i = 0; i < m; i++){
        if(ans[i]>=rans){
          indx = i;
          rans = ans[i];
        }
        ans[i]=0;
      }

      if(indx>0)
        update(root, indx, a, b);
  }
  flush(root);
  for(int i = 0; i < n; i++){
    cout << v[i] << endl;
  }
  
  return(0);
}
