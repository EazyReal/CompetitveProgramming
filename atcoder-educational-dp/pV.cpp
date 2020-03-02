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

//mt19937 mrand(random_device{}());
//const ll mod=1e9+7;
//int rnd(int x) { return mrand() % x;}
//ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
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
//#define int ll

int T;
const int maxn = 2e5+7;
int n; ll M;
ll dp[maxn]; //way that u is black,rooted at 1 at first
vector<int> G[maxn];
vector<ll> pre[maxn];
vector<ll> suf[maxn]; //so that dont need to calc inv
//int p[maxn];
//int s[maxn], t[maxn], dfn;
//vector<ll> vals;

ll dfs1(int u, int f) //first dp
{
	//debug(u);
	ll &ret = dp[u];
	ret = 1;
	//vals.clear();
	vector<ll> vals;
	for(int v:G[u])
	{
		if(v == f) {vals.pb(1); continue;}
		ll dpv = (dfs1(v, u)+1)%M;
		ret *= dpv;
		ret %= M;
		vals.pb(dpv);
	}
	int sz = G[u].size();
	//debug(sz);
	pre[u].resize(sz); //RE
	suf[u].resize(sz);
	rep(i, 0, sz)
	{
		pre[u][i] = i ? (pre[u][i-1]*vals[i]%M) : vals[i];
		suf[u][sz-1-i] = i ? (suf[u][sz-i]*vals[sz-1-i]%M) : vals[sz-1-i]; //%M WA
	}
	return ret;
}


//     fval(1/0)
//     |
//     1
// |   |   |
// u  1/0 1/0
void dfs2(int u, int f, ll f_val) //eular tree tour concept
{
	//debug(u);
	ll &ret = dp[u];
	ret = ret*f_val%M;
	rep(i, 0, G[u].size())
	{
		int v = G[u][i];
		if(v == f) continue;
		ll brother_way = ((i ? pre[u][i-1] : 1) * (i+1 < G[u].size() ? suf[u][i+1] : 1)) %M;
		ll f_is_1 = brother_way * f_val % M;
		dfs2(v, u, f_is_1 + 1);
	}

}



void solve()
{
	cin >> n >> M;
	int a, b;
	rep(i, 0, n-1) //1-indexed
	{
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}
	//dfn = 0;
	dfs1(1, 0);
	//cout << "HIHI" << endl;
	dfs2(1, 0, 1);

	rep(i, 1, n+1) cout << dp[i] << endl;

  return;
}


signed main()
{
  //fastIO();
	T = 1;
	//cin >> T; //this
  while(T--) solve();
  return 0;
}
/*
stuck:
	* do observations and see properties
	* binary search? DP? DS? flow?
	* be organized

before upload:
	* int overflow, array bounds
	* special cases (min, max, special)
*/
