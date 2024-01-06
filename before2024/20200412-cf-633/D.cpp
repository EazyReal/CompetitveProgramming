#include <bits/stdc++.h>
#define LOCAL
using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define repinv(i, st, n) for (int i = ((n)-1); i >= (st); --i)
#define MEM(a, b) memset(a, b, sizeof(a));
#ifdef LOCAL
#define debug(x) std::cerr << #x << ": " << x << endl
#else
#define debug(x) 860111
#endif
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fileIO(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

//mt19937 mrand(random_device{}());
//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod=1e9+7;
//int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
pii operator+(const pii&x, const pii&y) { return mp(x.X+y.X, x.Y+y.Y);}
pii operator-(const pii&x, const pii&y) { return mp(x.X-y.X, x.Y-y.Y);}
//INT_MAX, ULLONG_MAX, LLONG_MAX or numeric_limits<int>::min()

inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}

//------------------------------------------------------------------------//
int T;
const int maxn = 2e5+7;
int n;
//ll a[maxn];
vi G[maxn];
int d[maxn];

void dfs(int u, int p, int dep)
{
  d[u] = dep;
  for(int v: G[u]) if(v != p) dfs(v, u, dep+1);
}

//check T
void solve()
{
  cin >> n;
  int u, v;
  rep(i, 0, n) G[i].clear();
  rep(i, 0, n-1)
  {
    cin >> u >> v;
    u--; v--;
    G[u].pb(v);
    G[v].pb(u);
    //deg[u]++;
    //deg[v]++;
  }
  //n>=3 always have no leaf point
  /*int rt = -1;
  rep(i, 0, n) if(G[i].size() >= 2) rt = i;
  assert(rt != -1);*/

  //for min
  int minv;
  int rt = -1;
  rep(i, 0, n) if(G[i].size() >= 2) rt = i;
  assert(rt != -1);
  rep(i, 0, n) d[i] = 0;
  //d[rt] = 0;
  dfs(rt, -1, 0);
  bool has[2] = {0, 0};
  rep(i, 0, n) if(i!=rt && G[i].size()==1) has[d[i]%2] = 1;
  if(has[0] && has[1]) minv = 3;
  else minv = 1;

  //for max
  //for all leaf, loop up 1; remove reapeat, other can not repeat
  vector<int> rec(n, 0);
  rep(i, 0, n) if(G[i].size() == 1) rec[G[i][0]]++;
  int maxv = n-1;
  rep(i, 0, n) if(rec[i] > 1) maxv -= rec[i]-1;
  cout << minv << " " <<  maxv << endl;


  return;
}


signed main()
{
  fastIO();
  T = 1;
  //cin >> T; //this
  rep(tc, 1, T+1)
  {
    //cout << "Case #" << tc << ": ";
    solve();
  }
  return 0;
}
