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
const int maxn = 5e3+7;
int n, m;
int dp[maxn];

void solve()
{
	cin >> n >> m;
	int maxv = 0;
	rep(i, 1, n+1) maxv+= (i-1)/2, dp[i] = maxv;
	rep(i, 1, n+1) cout << dp[i] << " \n"[i==n-1];
	if(m > maxv) {cout << -1 << endl; return;}

	int curpos = 1;
	int mutable_n = n;
	vector<int> ans;
	repinv(i, 1, n+1)
	while(dp[i] <= m && mutable_n >= i)
	{
		debug(i); debug(m);
		m -= dp[i];
		mutable_n -= i;
		debug(mutable_n);
		debug(m);
		rep(pi, 0, i) ans.pb(curpos + pi);
		curpos = ans[ans.size()-1] + (ans.size()>1 ? ans[ans.size()-2] : 1) + 1;
		debug(curpos);
		assert(curpos <= 1000000000);
	}
	assert(mutable_n == 0);
	assert(m == 0);
	rep(i, 0, n) cout << ans[i] << " \n"[i==n];
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
