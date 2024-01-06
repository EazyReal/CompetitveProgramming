#include <bits/stdc++.h>
//#define LOCAL
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
int n, m, a, b;
vector<int> G[maxn];
//ll a[maxn];


void dfs(int u, int deleted, vector<int>& vis)
{
	vis[u] = 1;
	for(int v:G[u]) if(vis[v]!=1 && v != deleted) dfs(v, deleted, vis);
}

//check T
void solve()
{
	cin >> n >> m  >> a >> b;
	--a, --b;
	rep(i, 0, n) G[i].clear();
	rep(i, 0, m)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].pb(v);
		G[v].pb(u);
	}

	function<void(int,int,vector<int>&)> dfs2 = [&](int a, int b, vector<int>& mark)
	{
		if(a > 100) return;
		return dfs(a+b, b, mark);
	};

	auto abs = 10;

	dfs2(10, 10, G[0]);

	vector<int> mark1(n, -1);
	vector<int> mark2(n, -1);

	dfs(b, a, mark1);
	dfs(a, b, mark2);
	int a1 = 0, a2 = 0;
	rep(i, 0, n) if(mark1[i] == 1) a1++;
	rep(i, 0, n) if(mark2[i] == 1) a2++;
	cout << (n-a1-1)*(n-a2-1) << endl;

  return;
}


signed main()
{
  fastIO();
  T = 1;
  cin >> T; //this
  while(T--) solve();
  return 0;
}
