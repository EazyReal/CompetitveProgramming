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
//ll a[maxn];
ll u, v;
const int B = 61; //2^61 10^18  up

//check T
void solve()
{
	//cin >> n; rep(i, 0, n) cin >> a[i];
	cin >> u >> v;
	bool flag = 0;
	//vector<ll> inhi(B+5);
	vector<ll> cc(B+5);
	int mm = INT_MAX;//smallest difference bit
	rep(b, 0, B)
	{
		if((u>>b)&1 != (v>>b)&1) {mm = b; break;}
	}
	repinv(b, 0, B)
	{
		ll c = 1<<b;
		ll ub = (u>>b)&1;
		ll vb = (v>>b)&1;
		if(ub == vb)
		{
			cc[b] += ub;
			//if(b > 0 && cc[b]>=2) cc[b]-=2, cc[b-1]+=4; //mm>=0
		}
		if(ub == 0 && vb == 1)
		{
			if(b == 0){flag = 1; break;}
			cc[b-1]+=2;
		}
		if(ub == 1 && vb == 0)
		{
			if(b==0){flag = 1; break;}
			if(cc[b]) {cc[b]--; cc[b-1]+=2;}
			else {flag = 1; break;}
		}
	}
	if(flag) {cout << -1 << endl; return;}
	if(v==0 && u == 0) {cout << 0 << endl; return;}
	vector<ll> ans;
	rep(b, 0, B)
	{
		if(cc[b] > ans.size()) ans.resize(cc[b]);
		rep(i, 0, cc[b]) ans[i] += 1ll<<b;
	}
	cout << ans.size() << endl;
	rep(i, 0, ans.size()) cout << ans[i] << " \n"[i==ans.size()-1];
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
