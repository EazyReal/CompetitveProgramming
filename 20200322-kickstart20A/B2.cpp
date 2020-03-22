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
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0)
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
int a[50+5][30+5];
int s[50+5][30+5];
int dp[50+5][1500+5];//maxp

//check T
void solve(int tc)
{
	int n, k, p;
	cin >> n >> k >> p;
	rep(i, 1, n+1) rep(j, 1, k+1) cin >> a[i][j];
	rep(i, 1, n+1)
	{
		s[i][0] = 0;
		rep(j, 1, k+1) s[i][j] = s[i][j-1]+a[i][j];
	}
	rep(i, 0, n+1) rep(pp, 0, p+1) dp[i][pp] = 0;
	dp[0][p] = 0;
	repinv(pp, 0, p+1)
	{
		rep(i, 1, n+1)
		{
			rep(j, 0, k+1) if(j <= pp) dp[i][pp-j] = max(dp[i][pp-j], dp[i-1][pp]+s[i][j]);
		}
	}
	int ans = 0;
	rep(pp, 0, p+1) ans = max(ans , dp[n][pp]);


	cout << "Case #" << tc << ": " << ans << endl;
  return;
}


signed main()
{
  fastIO();
  T = 1;
  cin >> T; //this
  rep(tc, 1, T+1) solve(tc);
  return 0;
}
