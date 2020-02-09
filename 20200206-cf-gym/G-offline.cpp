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

//#include<ext/rope>
//using namespace __gnu_cxx;

int T, n;
const int maxn = 200000+5;
//#define ONLINE

struct Edge
{
  int to, type, val; //to version "to", push/pop , push val/pop ans id;
  Edge(int to, int type, int val):to(to), type(type), val(val){}
};

int ans[maxn];
vector<Edge> G[maxn];
deque<int> q;

void dfs(int cur)
{
  for(auto e : G[cur])
  {
    if(e.type == 1)
    {
      q.pb(e.val);
      dfs(e.to);
      q.pop_back();
    }else
    {
      ans[e.val] = q.front();
      q.pop_front();
      dfs(e.to);
      q.push_front(ans[e.val]);
    }
  }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    #define ONLINE
    #ifdef ONLINE
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);
    #endif

    cin >> n;
    int op, ver, val;
    int cnt = 0;
    rep(i, 1, n+1)
    {
      cin >> op;
      if(op == 1)
      {
        cin >> ver >> val;
        G[ver].pb(Edge(i, op, val));
      }else if(op == -1){
        cin >> ver;
        G[ver].pb(Edge(i, op, cnt++));
      }
    }

    q.clear(); assert(q.empty());
    dfs(0);

    rep(i, 0, cnt) cout << ans[i] << endl;

    return 0;
}
