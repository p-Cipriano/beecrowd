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

int n,t,q,k;
vector<int>v;

class treeNode{
  public:

  treeNode* ls;
  treeNode* rs;
  int l,r;
  int last;
  int toCheck;
  bool pass;
  int mn;

  treeNode(int l_, int r_){
    l = l_;
    r = r_;
    last = 0;
    toCheck = 0;
    pass = (l==r);
    mn = 0;
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

void prop(treeNode* cur, int nw, int check){
  
  if(cur->last==-inf)
    return;

  if(check-cur->last>t && cur->pass){
    cur->last = -inf;
    cur->toCheck = -inf;
    return;
  }

  if(!cur->pass)
    cur->toCheck = check;
  cur->pass = 1;
  cur->last = nw;
}


void update(treeNode* cur, int a, int b){

  if(cur->r < a || b < cur->l)
    return;

  if(cur->last==-inf)
    return;

  if(k-cur->last>t && cur->pass){
    cur->last = -inf;
    cur->toCheck = -inf;
    return;
  }

  if(cur->r == cur->l){
    cur->last = k;
    return;
  }

  if(a <= cur->l && cur->r <= b){
    cur->last = k;
    if(!cur->pass)
      cur->toCheck = k;
    cur->pass = 1;
    return;
  }
  
  if(cur->pass){
    prop(cur->rs, cur->last, cur->toCheck);
    prop(cur->ls, cur->last, cur->toCheck);
    cur->pass = 0;
  }

  update(cur->rs, a, b);
  update(cur->ls, a, b);

  return;
}

void getAns(treeNode* cur){

  if(cur->l == cur->r){
    if(k-cur->last<=t)
      v.pb(cur->l);
    return;
  }

  if(cur->pass){
    prop(cur->ls, cur->last, cur->toCheck);
    prop(cur->rs, cur->last, cur->toCheck);
    cur->pass = 0;
  }
  getAns(cur->ls);
  getAns(cur->rs);
}

void print(treeNode* cur){
  cout << cur->l << " " << cur->r << " -> " << cur->last << " " << cur->toCheck << " " << cur->pass << endl;
  if(cur->l!=cur->r){
    print(cur->ls);
    print(cur->rs);
  }
} 

int main(){ _
  
  while(cin >> n >> q >> t){

    v.clear();

    treeNode* root = buildTree(1,n);
    //cout << endl <<  0 << endl;
    //print(root);
    //cout << endl;


    for(k = 1; k<=q; k++){
      int a, b;
      cin >> a >> b;
      update(root, a, b);
      //cout << k << endl;
      //print(root);
      //cout << endl;
    }
    getAns(root);
    cout << v.size();
    for(int i = 0; i < v.size(); i++)
      cout << " " << v[i];
    cout << endl;

  }
  
  return(0);
}
