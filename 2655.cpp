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

int n,m,q;
vector<int>v;

class tri{
  public:

  int pos;
  int lv;
  int nv;

  tri(int pos_, int nv_, int lv_){
    pos = pos_;
    nv = nv_;
    lv = lv_;
  }
};

class treeNode{
  public:

  treeNode* ls;
  treeNode* rs;
  int l,r;
  vector<int> dist;
  tri* change;

  treeNode(int l_, int r_){
    l = l_;
    r = r_;
    dist.resize(m,0);
    for(int i = l; i<=r; i++){
      dist[v[i]]++;
    }
    change = new tri(-1,-1,-1);
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


void update(treeNode* cur, tri* toChange){
  cur->dist[toChange->lv]--;
  cur->dist[toChange->nv]++;

  if(cur->r == cur->l)
    return;

  if(toChange->pos <= cur->ls->r){
    update(cur->ls, toChange);
  }
  else{
    update(cur->rs, toChange);
  }

  return;
}

/*void prop(treeNode* cur){
  if(cur->change->pos==-1)
    return;
  
  if(cur->change->pos > cur->ls->r)
    update(cur->ls, cur->change);
  else
    update(cur->rs, cur->change);

  cur->change->pos = -1;
}*/

vector<int> query(treeNode* cur, int a, int b){
  if(cur->l >= a && cur->r <= b)
    return cur->dist;
  if(cur->l > b || cur->r < a){
    vector<int> a;
    a.resize(m,0);
    return a;
  }

  //prop(cur);

  vector<int>lset = query(cur->ls, a, b);
  vector<int>rset = query(cur->rs, a, b);

  for(int i = 0; i < m; i++){
    rset[i]+=lset[i];
  }
  /*cout << cur->l << cur->r << endl;
  for(set<int>::iterator it = rset.begin(); it!= rset.end(); ++it){
    cout << *it << endl;
  }
  cout << endl;
  */

  return rset;

}


int main(){ _
  
  cin >> n >> q >> m;
  m++;

  v.resize(n);

  for(int i = 0; i<n; i++){
    cin >> v[i];
  }

  treeNode* root = buildTree(0,n-1);

  for(int i = 0; i<q; i++){
    int com;
    cin >> com;

    if(com==1){
      int a,b;
      cin >> a >> b;
      a--;
      b--;
      vector<int> ans = query(root,a,b);
      int rans = 0;
      for(int i = 1; i < m; i++){
        //cout << ans[i] << endl;
        rans+=(ans[i]>0);
      }
      cout << rans << endl;
      //cout << endl;
    }
    else{
      int c,t;
      cin >> c >> t;
      c--;
      if(t == v[c]) continue;
      tri* toChange = new tri(c, t, v[c]);
      v[c] = t;
      update(root, toChange);
    }
  }
  
  return(0);
}
