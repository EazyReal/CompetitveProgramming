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

mt19937 mrand(random_device{}());
const ll mod=1e9+7;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//INT_MAX, ULLONG_MAX, LLONG_MAX or numeric_limits<int>::min()

inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}

//------------------------------------------------------------------------//
int T;
const int maxn = 2e5+5;
int n, m;
string s;
int p[maxn];
ll pre[26][maxn];
ll ans[26];


void solve()
{
	cin >> n >> m;
	cin >> s;
	rep(i, 0, m) cin >> p[i];
	//
	rep(c, 0, 26) pre[c][0] = 0ll;
	rep(i, 0, n) rep(c, 0, 26)
	{
		pre[c][i+1] = pre[c][i] + ll(c == int(s[i]-'a'));
	}
	/*rep(c, 0, 26)
	{
		debug(c);
		rep(i, 1, n+1) cout << pre[c][i] << " \n"[c==25];
	}*/
	//cout <<
	//debug(T);
	rep(c, 0, 26) ans[c] = 0;;
	rep(i, 0, m) rep(c, 0, 26)
	{
		ans[c] += pre[c][p[i]];
	}
	rep(c, 0, 26) ans[c] += pre[c][n];

	rep(c, 0, 26) cout << ans[c] << " \n"[c==25];

  return;
}


signed main()
{
  fastIO();
  cin >> T;
  //T = 1;
  while(T--) solve();
  return 0;
}
