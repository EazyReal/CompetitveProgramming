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
//ll powmod(ll a,ll b, ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
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
int n, m;

#define ll int
ll powmod(ll a,ll b, ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
/*
void solve()
{
	cin >> n >> m;
	vector<int> a(n);
	rep(i, 0, n) cin >> a[i];
	sort(all(a));
	//vector<int> d(n-1);
	//rep(i, 0, n-1) d[i] = a[i+1]-a[i];
	vector<int> c(m);
	int ans = 1;
	rep(i, 0, n)
	{
		int now = a[i];
		rep(j, 0, m) if(c[j])
		{
			if((now-j)%m == 0) {cout << 0 << endl;}
			ans = ans * powmod((now-j)%m, c[j], m) % m;
		}
		c[now%m]++;
	}
	cout << ans << endl;
  return;
}
*/

/*
2e5 999
2 4 6 8 10
*/
void solve()
{
	cin >> n >> m;
	vector<int> a(n);
	rep(i, 0, n) cin >> a[i];
	sort(all(a));
	rep(i, 0, n-1) if(a[i] == a[i+1]) {cout << 0 << endl; return;} //AC !?
	//vector<int> d(n-1);
	//rep(i, 0, n-1) d[i] = a[i+1]-a[i];
	int id = 0;
	vector<int> c(m);
	int ans = 1;
	rep(i, 1, n)
	{
		int now = a[i];
		while(now-a[id] >= m)
		{
			c[a[id]%m]++;
			if(now-a[id]%m == 0) {cout << 0 << endl; return;} //==m in contest
			id++;
		}
		rep(j, id, i) ans = ans*(now-a[j])%m;
		rep(j, 0, m) if(c[j])
		{
			if((now-j)%m == 0) {cout << 0 << endl; return;}
			ans = ans * powmod((now-j)%m, c[j], m) % m;
		}
	}
	cout << ans << endl;
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
