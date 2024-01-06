#include <bits/stdc++.h>

//when use implicit treap
//key = index(unused), record subtree size
struct Node
{
  int pri, key, sz, val;
  Node *lc, *rc;
  Node(){};
  //syntax sugar
  Node(int val, int key) :pri(rand()), key(key), sz(1), val(val), mark(0) {};
  Node(int val) :pri(rand()), sz(1), val(val), mark(0) {};
}

Node* merge(Node* a, Node* b) //key a < key b
{
    if (!a) return b; //base case
    if (!b) return a;
    if(a−>pri > b−>pri)//pri a bigger => a as root
    {
        a−>r = merge(a−>r, b); //key b bigger => merge b and rc of a
        return a;
    }
    //b as root
    b−>l = merge(a, b−>l); //key a smaller => merge a and lc of b
    return b;
}

//result will store in a, b
void split(Node* c, int k, Node*& a, Node*& b)
{
  if (!c) a = b = nullptr; //base case
  else if (c−>key <= k)
  {
    //key of c <= k => Node c and lc <= k
    a = c;
    split(c−>r, k, a−>r, b);
  }
  else
  {
    b = c;
    split(c−>l, k, a, b−>l);
  }
}
