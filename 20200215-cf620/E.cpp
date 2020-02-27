// 71854263	Feb/25/2020 19:50UTC+8	maxwill	E - 1-Trees and Queries	GNU C++17	Accepted	951 ms	16600 KB
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

//mt19937 mrand(random_device{}());
const ll mod=1e9+7;
//int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//INT_MAX, ULLONG_MAX, LLONG_MAX or numeric_limits<int>::min()

//------------------------------------------------------------------------//

//should know how to implement on contest

const int maxn = 1e5+5;
int T;
int n, q;
const int max2pow = 20; //19 is used actually
//2^20 ~ 1e6 > maxn = 1e5
int p[max2pow+2][maxn];
vector<int> G[maxn];
int d[maxn];

void build_lca(int u, int f)
{
  d[u] = d[f]+1;
  p[0][u] = f; //1st parent = f
  rep(i, 0, max2pow) p[i+1][u] = p[i][p[i][u]]; //i+1 => RE
  for(int v:G[u]) if(v!=f) build_lca(v, u);
}

int path_lca(int a, int b)
{
  int ret = 0;
  if(d[a] < d[b]) swap(a, b);
  repinv(i, 0, max2pow) //max2pow-1 ok
  {
    if(d[p[i][a]] >= d[b])
    {
       a = p[i][a];
       ret += 1<<i;
    }
  }
  if(a == b) return ret;
  repinv(i, 0, max2pow) //max2pow-1 ok
  {
    if(p[i][a] != p[i][b])
    {
      a = p[i][a];
      b = p[i][b];
      ret += 1<<(i+1);
    }
  }
  return ret+2; //the last part a - pab - b
}

void solve()
{
  cin >> n;
  int x, y, a, b, qd;
  rep(i, 0, n-1)
  {
    cin >> a >> b;
    G[a].pb(b);
    G[b].pb(a);
  }
  rep(i, 0, max2pow) p[i][0] = 0; //modified => no TLE
  build_lca(1, 0);
  cin >> q;
  rep(i, 0, q)
  {
    cin >> x >> y >> a >> b >> qd;
    int min_same_parity = INT_MAX; //>maxk = 1e9
    int without_xy = path_lca(a, b);
    int with_xy = min(path_lca(a, x)+path_lca(y, b), path_lca(b, x)+path_lca(y, a)) + 1;
    //debug(with_xy);debug(without_xy);
    if(without_xy%2 == qd%2) min_same_parity = without_xy;
    if(with_xy%2 == qd%2) min_same_parity = min(min_same_parity, with_xy);
    cout << (min_same_parity <= qd ? "YES" : "NO") << endl;
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
