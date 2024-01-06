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
int n, m; //.BR
const int maxn = 30+5;
char a[maxn][maxn];
ll dp[2][maxn];

void solve()
{
	cin >> n >> m;
	char c;
	rep(i, 0, n)rep(j, 1, m+1)
	{
		cin >> a[i][j]; //1-indexed
	}
	auto ok = [&](int x, int y) {
		bool flag = true;
		if(a[x][y] == 'B')
		{
			rep(i, 0, x+1)rep(j, 1, y+1) flag &= a[i][j] != 'R';
		}else if(a[x][y] == 'R')
		{
			rep(i, x, n)rep(j, y, m+1) flag &= a[i][j] != 'L';
		}
		return flag;
	};
	auto can_first_blue = [&](int x, int y) {
		bool flag = false;
		rep(j, 1, y+1) flag |= a[x][j] == 'R';
		rep(j, y+1, m+1) flag |= a[x][j] == 'B';
		return !flag;
	};
	bool allok = true;

	rep(i, 0, n)rep(j, 1, m+1) allok &= ok(i, j);
	if(!allok)
	{
		cout << 0 << endl;
		return;
	}

	int cur = 0, nxt = 1;
	rep(j, 0, m+1) dp[cur][j] = can_first_blue(0, j);//can mem
	//rep(j, 0, m+1) cout << dp[cur][j] << ' '; cout << endl;
	rep(i, 1, n)
	{
		rep(j, 0, m+1) dp[nxt][j] = 0ll;
		rep(j, 0, m+1)rep(j2, 0, j+1) //j2 <= j
		{
			dp[nxt][j2] += dp[cur][j]*can_first_blue(i, j2);
		}
		swap(nxt, cur);
		//rep(j, 0, m+1) cout << dp[cur][j] << ' '; cout<< endl;
	}
	//rep(i, 0, n) {rep(j, 0, m) cout << dp[i][j] << ' '; cout<< endl;}
	ll ans = 0ll;
	rep(j, 0, m+1) ans += dp[cur][j];
	cout << ans << endl;

  return;
}


signed main()
{
  //fastIO();
  //cin >> T;
  T = 1;
  while(T--) solve();
  return 0;
}
