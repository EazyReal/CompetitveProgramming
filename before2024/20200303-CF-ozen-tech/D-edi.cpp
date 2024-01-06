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
const int maxn = 1e3+7;
const int maxb = 11;
int n;
vi G[maxn];


void solve()
{
	cin >> n;
	int a, b;
	vector<int> degree(n+1, 0);
	rep(i, 0, n-1)
	{
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
		degree[a]++;
		degree[b]++;
	}
	vector<int> leafs;
	rep(i, 1, n+1) if(degree[i] == 1) leafs.pb(i);
	int u, v, w;
	while(1)
	{
		if(leafs.size() == 1) {cout << "! " << leafs[0] << endl; return;}
		u = leafs.back(); leafs.pop_back();
		v = leafs.back(); leafs.pop_back();
		cout << "? " << u << " " << v << endl;
		cin >> w;
		if(u == w) {cout << "! " << u << endl; return;}
		if(v == w) {cout << "! " << v << endl; return;}
		for(int x : G[u])
		{
			degree[x]--;
			if(degree[x] == 1) leafs.pb(x);
		}
		for(int x : G[v])
		{
			degree[x]--;
			if(degree[x] == 1) leafs.pb(x);
		}
	}

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
