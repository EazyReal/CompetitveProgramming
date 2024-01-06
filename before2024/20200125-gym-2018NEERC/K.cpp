//69530997	Jan/26/2020 01:06UTC+8	maxwill	K - King Kog's Reception	GNU C++17	Accepted	732 ms	63800 KB
#include <bits/stdc++.h>

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

int q;
const int maxq = 3*1e5+5;
const int maxt = 1e6+5;
int rec[maxq];

class Node
{
public:
  ll sum, et; //sum of interval, end time of interva;
  Node up(const Node& lc, const Node& rc)
  {
    sum = lc.sum + rc.sum;
    et = max(lc.et+rc.sum, rc.et);
    return *this;
  }
};

//class SegTree
//{
//define params
#define M (l+r>>1)
#define LC l, M, rt<<1
#define RC M+1, r, rt<<1|1

//public:
  static const int sz = 4*maxt+5;
  //static const int sz = 1e5;
  Node nodes[sz];

  void update(int t, ll val, int l = 1, int r = maxt, int rt = 1)
  {
    if(l == r)
    {
      nodes[rt].sum = val;
      nodes[rt].et = l + val;
      return;
    }
    if(t > M) update(t, val, RC);
    else update(t, val, LC);
    nodes[rt].up(nodes[rt<<1], nodes[rt<<1|1]);
  }

  Node query(int lb, int rb, int l = 1, int r = maxt, int rt = 1)
  {
    if(lb <= l && r <= rb) return nodes[rt];
    //all in RC or LC
    if(lb > M) return query(lb, rb, RC);
    if(rb <= M) return query(lb, rb, LC);
    Node ret;
    return ret.up(query(lb, rb, LC), query(lb, rb, RC));
  }
//};

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cout << "hihihi";
    cin >> q;
    char op;  ll val;
    //SegTree tree;
    rep(i, 0, q)
    {
      cin >> op >> rec[i];
      if(op == '+')
      {
        cin >> val;
        update(rec[i], val);
      }
      if(op == '-') update(rec[--rec[i]], 0ll);
      if(op == '?') cout << max(0ll, query(1, rec[i]).et - rec[i]) << endl;
    }
    return 0;
}
