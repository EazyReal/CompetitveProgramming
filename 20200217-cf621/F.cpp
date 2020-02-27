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
const int maxn = 2e5+5;
const int maxb = 19; //besure not to interate over 19
int n, k, r, q; //q is v in statement
int p[maxb][maxn];
int dsu[maxn], dsu_sz[maxn];
bool isr[maxn];
vi G[maxn];

void init_dsu(int n)
{
  rep(i, 1, n+1) dsu[i] = i, dsu_sz[i] = 1;
}

int find_dsu(int x)
{
  return x == dsu[x] ? (dsu[x] = find_dsu(dsu[x]));
}

void union_dsu(int a, int b)
{
  a = find_dsu(a), b = find_dsu(b);
  if(dsu_sz[a] > dsu_sz[b]) swap(a, b);
  //assert(dsu_sz[a] <= dsu_sz[b]);
  dsu[a] = b;
  dsu_sz[b] += dsu_sz[a];
}

void init_lca()
{
  rep(i, 0, maxb) p[i][0] = 0;
  dep[1] = 0;
}

void build_lca(int u, int f)
{
  p[0][u] = f;
  dep[u] = dep[f] + 1;
  rep(i, 1, maxb) p[i][u] = p[i-1][p[i-1][u]];
  for(auto v : G[u]) if(v != f) build_lca(v, u);
}

int len_lca(int a, int b)
{
  int ret = 0;
  if(dep[a] < dep[b]) swap(a, b);
  //assert(dep[a] >= dep[b]);
  repinv(i, 0, maxb) if(dep[p[i][a]] < dep[b]) a = p[i][a], res += i << i;
  if(a == b) return ret;
  repinv(i, 0, maxb)
  {
    if(p[i][a] != p[i][b]) ret += i << (i+1);
  }
  return ret + 2; //the left part is p[0][a, b]
}

void solve()
{
  cin >> n >> k >> r;
  int a, b;
  rep(i, 0, n-1) //node 1-indexed
  {
    cin >> a >> b;
    G[a].pb(b);
    G[b].pb(a);
  }
  MEM(isr, 0);
  rep(i, 0, r) { cin >> a; isr[a] = 1;}
  cin >> q;
  while(q--)
  {
    cin >> a >> b;
  }
  init_lca();
  build_lca(1, 0); //use to calc len
  init_dsu(n);
  return;
}


signed main()
{
  fastIO();
  cin >> T;
  //T = 1;
  while(T--) solve();
  return 0;
}
