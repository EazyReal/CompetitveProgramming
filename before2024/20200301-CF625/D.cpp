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
int n, m, k;
int a[maxn];
vi G[maxn], H[maxn];
int d[maxn];
bool vis[maxn];

void solve()
{
	cin >> n >> m;
	int u, v;
	rep(i, 0, m)
	{
		cin >> u >> v;
		G[u].pb(v);
		H[v].pb(u);
	}
	cin >> k;
	rep(i, 0, k) cin >> a[i];

	//bfs for d to t
	queue<int> q;
	int s = a[0], t = a[k-1];
	memset(d, -1, sizeof(d));
	q.push(t); d[t] = 0;
	while(!q.empty())
	{
		int cur = q.front(); q.pop();
	  for(int nxt:H[cur]) if(d[nxt] == -1) {q.push(nxt), d[nxt] = d[cur]+1;}
	}
	//rep(i, 1, n+1) debug(d[i]);

	memset(vis, 0, sizeof(vis));

	int minv = 0;
	int maxv = 0;
	vis[s] = 1;
	rep(i, 0, k-1) //i = cur
	{
		int minto = INT_MAX;
		int minto2 = INT_MAX;
		for(int x : G[a[i]]) if(!vis[x]) minto = min(minto, d[x]);
		//debug(minto);
		vis[a[i+1]] = 1;//this step may need back track, rule not clear, ignore
		bool flag = 0;
		for(int x : G[a[i]]) if(!vis[x] && d[x] == minto) flag = 1;

		if(d[a[i+1]] != minto) {minv++, maxv++;}
		else if(flag) {maxv++; }
		else maxv = maxv;
		//vis[a[i]] = 1;
	}
	cout << minv << " " << maxv << endl;
  return;
}


signed main()
{
  fastIO();
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
