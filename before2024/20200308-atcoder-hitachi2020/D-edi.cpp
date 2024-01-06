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

const int maxn = 2e5+7;
int n;
ll T;
//ll a[maxn];
vector<ll> m, b;

bool cmp(int x, int y)
{
	return (m[x])*(b[y]+1) > (m[y])*(b[x]+1);
}

ll f(ll pre, int id)
{
	pre++;
	return pre + m[id]*pre + b[id];
}

void solve()
{
	cin >> n >> T;
	m.resize(n);
	b.resize(n);
	vector<ll> consts; //store bs
	vector<int> lines; //store id
	rep(i, 0, n)
	{
		cin >> m[i] >> b[i];
		if(m[i] == 0) consts.pb(b[i]+1); //1 more
		else lines.pb(i);
	}
	/*sort(all(lines), [&](int x, int y)->bool
	{
		return (m[x])*(b[y]+1) > (m[y])*(b[x]+1); //pri by swapping proof
	});*/
	//rep(i, 0, lines.size()) cout << lines[i] << " \n"[i==lines.size()-1];
	sort(all(lines), cmp);
	sort(all(consts));
	//max T = 1000000000
	//max log2T = 30
	const int maxlogT = 31;
	/*auto f = [&](ll pre, int id)->ll
	{
		pre++;
		return pre + m[id]*pre + b[id];
	};*/
	//dp[i] means the least time required for shop i stores
	vector<ll> dp(maxlogT+5, 1e9+5);
	dp[0] = 0ll;
	//cout << "T: " << T << endl;
	rep(i, 0, lines.size())
	repinv(j, 0, maxlogT) //direction prohibits reuse
	{
		//debug(i);
		if(dp[j] <= T)
		{
			//cout << "f : " << i << " " <<  j+1 << " " << f(dp[j], i) << endl;
			dp[j+1] = min(dp[j+1], f(dp[j], lines[i])); //lines...
		}
	}
	//for(auto x : dp ) cout << x << endl;
	int ans = 0;
	ll timeused;
	rep(i, 0, maxlogT+1)
	{
		ll curt = dp[i];
		if(curt > T) break; //later is not ok
		int id = 0;
		while(id < consts.size() && curt+consts[id] <= T) curt += consts[id++];
		ans = max(ans, i+id);
		if(ans == i+id) timeused = curt;
	}

	cout << ans << endl;
	//cout << timeused <<endl;
}


signed main()
{
  fastIO();
  solve();
  return 0;
}
