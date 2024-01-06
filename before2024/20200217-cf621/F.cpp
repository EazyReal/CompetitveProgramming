//71953032	Feb/27/2020 13:59UTC+8	maxwill	F - Cow and Vacation	GNU C++17	Accepted	1388 ms	67800 KB
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define repinv(i, st, n) for (int i = ((n)-1); i >= (st); --i)
#define MEM(a, b) memset(a, b, sizeof(a));

#define debug(x) std::cout << #x << ": " << x << endl
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fileIO(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

mt19937 mrand(random_device{}());
const ll mod=1e9+7;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//INT_MAX, ULLONG_MAX, LLONG_MAX or numeric_limits<int>::min()

//------------------------------------------------------------------------//
int T;
const int maxn = (2e5+5)*2;
const int maxb = 20; //besure not to interate to 19
int n, k, r, q; //q is v in statement
int dep[maxn], dis[maxn], from[maxn];
vi rs;
vi G[maxn];

namespace dsu
{
  int dsu[maxn], dsu_sz[maxn];
  void init(int n)
  {
    rep(i, 0, n+1) dsu[i] = i, dsu_sz[i] = 1;
  }

  int find(int x)
  {
    return x == dsu[x] ? dsu[x] : (dsu[x] = find(dsu[x]));
  }

  void unite(int a, int b)
  {
    a = find(a), b = find(b);
    if(dsu_sz[a] > dsu_sz[b]) swap(a, b);
    //assert(dsu_sz[a] <= dsu_sz[b]);
    dsu[a] = b;
    dsu_sz[b] += dsu_sz[a];
  }
}

namespace lca{
  int p[maxb][maxn];
  void dfs(int u, int f)
  {
    p[0][u] = f;
    dep[u] = dep[f] + 1;
    for(auto v : G[u]) if(v != f) dfs(v, u);
  }

  int lca(int a, int b)
  {
    if(dep[a] < dep[b]) swap(a, b);
    //assert(dep[a] >= dep[b]);
    repinv(i, 0, maxb) if(dep[p[i][a]] >= dep[b]) a = p[i][a]; //< -> >=...
    if(a == b) return a;
    repinv(i, 0, maxb)
    {
      if(p[i][a] != p[i][b]) a = p[i][a], b = p[i][b];
    }
    return p[0][a];
  }

  void build(int n)
  {
    dep[0] = -1;
    dfs(1, 0);
    p[0][1] = 1;
    rep(i, 1, maxb) rep(u, 1, n+1) p[i][u] = p[i-1][p[i-1][u]];
  }

  int dist(int a, int b)
  {
    return dep[a] + dep[b] - 2*dep[lca(a, b)];
  }
}

void add_edge(int u, int v)
{
  G[u].pb(v);
  G[v].pb(u);
}

void solve()
{
  //read graph and rest stations
  cin >> n >> k >> r;
  int a, b;
  rep(i, 1, n) //node 1-indexed
  {
    cin >> a >> b;
    add_edge(a, n+i); //n+i from n+1 to 2n-1
    add_edge(n+i, b);
  }
  n = 2*n-1;
  rep(i, 0, r) { cin >> a; rs.pb(a);}

  //cout << "end of reading rests";

  //process
  lca::build(n);
  dsu::init(n);
  MEM(from, 0);
  queue<int> que;
  for(auto ri : rs) que.push(ri), from[ri] = ri, dis[ri] = 0;
  while(!que.empty())
  {
    int u = que.front(); que.pop();
    if(dis[u] >= k) continue;
    for(int v:G[u])
    {
      if(!from[v]) from[v] = from[u], dis[v] = dis[u] + 1, que.push(v);
      else dsu::unite(from[u], from[v]);
    }
  }
  //cout << "end of process";

  //answer queries
  auto go = [&](int u, int v, int t) -> int
  {
    int c = lca::lca(u, v);
    if(dep[u] - dep[c] < t) //see as go from the other side
    {
      t = dep[v] - dep[c] - (t - (dep[u] - dep[c]));
      swap(u, v);
    }
    rep(i, 0, maxb)if(t & 1<<i)  u = lca::p[i][u];
    return u;
  };
  cin >> q;
  while(q--)
  {
    cin >> a >> b;
    //no rest
    if(lca::dist(a, b) <= 2*k) { cout << "YES\n"; continue;}
    //rest
    a = go(a, b, k);
    b = go(b, a, k);
    //debug(a); debug(b);
    //debug(dsu::find(from[a]));
    //debug(dsu::find(from[b]));
    if(from[a] && from[b] && dsu::find(from[a]) == dsu::find(from[b]) ) cout << "YES\n";
    else cout << "NO\n";
  }
  return;
}


signed main()
{
  fastIO();
  //cin >> T;
  T = 1;
  while(T--) solve();
  return 0;
}

/*
8 3 3
7 2
2 3
3 4
4 5
4 6
6 1
1 8
2 5 8
56
1 2
1 3
1 4
1 5
1 6
1 7
1 8
2 1
2 3
2 4
2 5
2 6
2 7
2 8
3 1
3 2
3 4
3 5
3 6
3 7
3 8
4 1
4 2
4 3
4 5
4 6
4 7
4 8
5 1
5 2
5 3
5 4
5 6
5 7
5 8
6 1
6 2
6 3
6 4
6 5
6 7
6 8
7 1
7 2
7 3
7 4
7 5
7 6
7 8
8 1
8 2
8 3
8 4
8 5
8 6
8 7
*/
