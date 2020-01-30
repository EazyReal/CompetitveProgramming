//POJ no nullptr, no bits;
//21277167	maxwill	3580	Accepted	6148K	1594MS	G++	4954B	2020-01-29 13:34:41
//my style

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define debug(x) std::cout << #x << ": " << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int n, m;
const int MOD = 1e7;

#define nullptr NULL

struct Node
{
  //node data
  int pri, sz, val;
  Node *lc, *rc;
  //interval val, lazy marks
  int minv;
  int addv;
  bool rev;
  Node(){};
  //syntax sugar
  Node(int val) :pri(rand()%MOD), sz(1), val(val), minv(val), rev(false), addv(0), lc(nullptr), rc(nullptr) {};
};

inline int sz(Node *a){return a?a->sz:0;} //care

//implementation of my style, care pull() should consider lazy mark
void push(Node *a)
{
  if(!a) return;
  if(a->rev)
  {
    swap(a->lc, a->rc);
    if(a->lc) a->lc->rev ^= 1;
    if(a->rc) a->rc->rev ^= 1;
    a->rev = false;
  }
  if(a->addv != 0)
  {
    a->val += a->addv;
    a->minv += a->addv;
    if(a->lc) a->lc->addv += a->addv;
    if(a->rc) a->rc->addv += a->addv;
    a->addv = 0;
  }
  return;
}

void pull(Node *a)
{
  a->sz = sz(a->lc) + sz(a->rc) + 1;
  a->minv = a->val;
  //key : push children before pull (maintain inside) or consider addv lazy mark
  if(a->lc) a->minv = min(a->minv, a->lc->minv + a->lc->addv);
  if(a->rc) a->minv = min(a->minv, a->rc->minv + a->rc->addv);
}

//for debugging , print tree inorder
void inorder(Node *root)
{
  if(!root) return;
  //cout << "hihi";
  push(root);
  inorder(root->lc);
  cout << root->val  << " ";
  inorder(root->rc);
  pull(root);
  return;
}

//treap op
Node *merge(Node *a, Node *b) //key a < key b
{
  if(!a) return b;
  if(!b) return a;
  if(a->pri > b->pri)
  {
    push(a);
    a->rc = merge(a->rc, b);
    pull(a);
    return a;
  }
  push(b);
  b->lc = merge(a, b->lc);
  pull(b);
  return b;
}

//implicit treap, a will be size k
void split(Node* c, int k, Node*& a, Node*& b)
{
  if(!c) {a = b = nullptr; return;}
  push(c); //any root will get pushed first
  if(sz(c->lc) < k)
  {
    a = c;
    split(c->rc, k-sz(c->lc)-1, a->rc, b);
    pull(a);
  }else{
    b = c;
    split(c->lc, k, a, b->lc);
    pull(b);
  }
}

void clear(Node* p)
{
  if(!p) return; //no this RE
  clear(p->lc);
  clear(p->rc);
  delete p;
}

//interval op
//root should pass by reference
void add_(Node *&root, int l, int r, int x)
{
  Node *a, *b, *c, *d;
  split(root, r, a, b); //a = [1, r]
  split(a, l-1, c, d); //d = [l, r]
  d->addv += x;
  root = merge(merge(c, d), b);
}

void reverse_(Node *&root, int l, int r)
{
  Node *a, *b, *c, *d;
  split(root, r, a, b); //a = [1, r]
  split(a, l-1, c, d); //d = [l, r]
  d->rev ^= 1;
  root = merge(merge(c, d), b);
}

void revolve_(Node *&root, int l, int r, int k)
{
  k = k%(r-l+1); //care
  Node *a, *b, *c, *d;
  split(root, r, a, b); //a = [1, r]
  split(a, l-1, c, d); //d = [l, r]
  Node *e, *f;
  split(d, r-l+1-k, e, f);
  root = merge(merge(c, merge(f, e)), b);
}

void insert_(Node *&root, int pos, int x) //discover pass py value of point root here
{
  Node *a, *b;
  split(root, pos, a, b);
  root = merge(merge(a, new Node(x)), b);
}

void delete_(Node *&root, int pos)
{
  Node *a, *b, *c, *d;
  split(root, pos, a, b); //a = [1, pos], b = [pos+1, n]
  split(a, pos-1, c, d);  //c = [1, pos-1]
  delete d;
  root = merge(c, b);
}

void min_(Node *&root, int l, int r)
{
  Node *a, *b, *c, *d;
  split(root, r, a, b); //a = [1, r]
  split(a, l-1, c, d); //d = [l, r]
  //push(d); pull(d);
  cout << d->minv << endl;
  root = merge(merge(c,d), b);
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //srand(time(NULL));
    srand(1080);
    //freopen("in", "r", stdin);
    cin >> n;
    Node *root = nullptr;
    int tmp;
    rep(i, 0, n)
    {
      cin >> tmp;
      root = merge(root, new Node(tmp));
    }
    cin >> m;
    string op; int l, r, x;
    rep(i, 0, m)
    {
      cin >> op;
      if(op == "ADD") {cin >> l >> r >> x; add_(root, l, r, x);}
      if(op == "REVERSE") {cin >> l >> r; reverse_(root, l, r);}
      if(op == "REVOLVE") {cin >> l >> r >> x; revolve_(root, l, r, x);}
      if(op == "INSERT") {cin >> l >> x; insert_(root, l, x);}
      if(op == "DELETE") {cin >> l; delete_(root, l);}
      if(op == "MIN") {cin >> l >> r; min_(root, l, r);} //cout in min
      //inorder(root); cout << endl;
    }
    //inorder(root); cout << endl;
    clear(root);

    return 0;
}

/*
5 1 2 3 4 5
12
INSERT 4 8
REVERSE 1 5
REVOLVE 1 5 2
REVERSE 1 3
REVOLVE 1 3 5
MIN 4 5
ADD 1 3 2
DELETE 1
REVOLVE 1 4 1
INSERT 1 9
REVERSE 3 4
MIN 1 3


5 1 2 3 4 5
12
INSERT 4 8
1 2 3 4 8 5
REVERSE 1 5
8 4 3 2 1 5
REVOLVE 1 5 2
2 1 8 4 3 5
REVERSE 1 3
8 1 2 4 3 5
REVOLVE 1 3 5
1 2 8 4 3 5
MIN 4 5
3
1 2 8 4 3 5
ADD 1 3 2
3 4 10 4 3 5
DELETE 1
4 10 4 3 5
REVOLVE 1 4 1
3 4 10 4 5
INSERT 1 9
3 9 4 10 4 5
REVERSE 3 4
3 9 10 4 4 5
MIN 1 3
3
3 9 10 4 4 5
*/
