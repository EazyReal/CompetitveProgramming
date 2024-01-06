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
#define int ll
int T;
const int maxn = 2e5+7;
int n;
int a[maxn], b[maxn], c[maxn];
int sub0[maxn], subd0[maxn]; // 0 provider , 0 taker
vi G[maxn];
int ans; //ll

void dfs(int u, int minv, int p)
{
  //bool mal = 0;
  if(b[u] == 0 && c[u] == 1) sub0[u]++;//, mal = 1; //supply of 0
  if(b[u] == 1 && c[u] == 0) subd0[u]++;//, mal = 1; //demand of 0
  for(int v : G[u]) if(v != p)
  {
    dfs(v, min(a[v], minv), u);
    sub0[u] += sub0[v];
    subd0[u] += subd0[v];
  }
  /*
  if(sub0[u] != 0 && subd0[u]!= 0)
  {
    ans += minv*min(sub0[u], subd0[])*2;
    //mal = 0;
  }*/
  int trade = min(sub0[u], subd0[u]);
  ans += minv*trade*2;
  sub0[u] -= trade;
  subd0[u] -= trade;
  return;
}

//check T
void solve()
{
  cin >> n;
  int cnt0 = 0, cntd0 = 0;
  rep(i, 1, n+1)
  {
    cin >> a[i] >> b[i] >> c[i];
    cnt0 += b[i] == 0;
    cntd0 += c[i] == 0;
  }
  int x, y;
  rep(i, 0, n-1)
  {
    cin >> x >> y;
    G[x].pb(y);
    G[y].pb(x);
  }
  if(cnt0 != cntd0)
  {
    cout << -1 << endl;
    return;
  }
  ans = 0;
  dfs(1, a[1], -1);
  ans += a[1]*2*sub0[1];
  cout << ans << endl;
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
