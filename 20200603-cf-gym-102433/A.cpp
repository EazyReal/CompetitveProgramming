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
//ll a[maxn];
vector<pii> G[maxn];
int w[maxn];
int sub[maxn]; //subtree size rooted at 1
int subn[maxn];
int cost[maxn]; //subtree cost rooted at 1, the i th node part
int es[maxn]; //path sum rooted at 1
int p[maxn];//parent srooted at 1
int pw[maxn];

int ans[maxn];

int dfs1(int u, int f)
{
  p[u] = f;
  sub[u] = w[u];
  cost[u] = 0;
  for(pii e: G[u])if(e.X!=f)
  {
    sub[u] += dfs1(e.X, u);
    cost[u] += sub[e.X]*e.Y + cost[e.X];
  }
  return sub[u];
}

int dfs2(int u, int f, int pwval)
{
  subn[u] = 1;
  es[u] = 0;
  pw[u] = pwval;
  for(pii e: G[u])if(e.X!=f)
  {
    subn[u] +=  dfs2(e.X, u, e.Y);
    es[u] += e.Y*subn[e.X] + es[e.X];
  }
  return subn[u];
}

void dfs3(int u, int f)
{
  for(pii e: G[u])if(e.X!=f)
  {
    cost[e.X] = cost[u] + (sub[1] - 2*sub[e.X])*e.Y;   
    es[e.X] = es[u] + (subn[1] - 2*subn[e.X])*e.Y;
    dfs3(e.X, u);
  }
}


//check T
void solve()
{
  //cin >> n; rep(i, 0, n) cin >> a[i];
  cin >> n;
  int a, b, wi;
  rep(i, 1, n+1) cin >> w[i];
  rep(i, 0, n-1)
  {
    cin >> a >> b >> wi;
    G[a].pb({b,wi});
    G[b].pb({a,wi});

  }
  dfs1(1, 0);
  dfs2(1, 0, 0);
  //cout << cost[1] + es[1]*w[1]  << endl;
  //ans[1] = cost[1];
  dfs3(1, 0);
  rep(i, 1, n+1)
  {
    cout << cost[i] + es[i]*w[i] << endl;
  }
  return;
}


//g++ -o out -std=c++11 A.cpp

signed main()
{
  fastIO();
  T = 1;
  //scin >> T; //this
  rep(tc, 1, T+1)
  {
    //cout << "Case #" << tc << ": ";
    solve();
  }
  return 0;
}
