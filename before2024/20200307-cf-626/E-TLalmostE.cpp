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
const int maxn = 2e5+7;
int n, m;

//check T
void solve()
{
	scanf("%d%d", &n, &m);
	vector<ll> a(n);
	rep(i, 0, n) scanf("%lld", &a[i]);
	vector<vector<int>> G(n); //right to left
	int u, v;
	rep(i, 0, m)
	{
		scanf("%d%d", &u, &v);
		G[--v].pb(--u);
	}
	//map<set<int>, ll> lsum; //the right vertex with same l set
	map<vector<int>, ll> lsum;
	rep(i, 0, n)
	{
		if(G[i].size() == 0) continue;
		sort(all(G[i]));
		lsum[G[i]] += a[i];
	}
	//ll ans = lsum.begin()->Y; //m>=1
	ll ans = 0;
	for(auto& s : lsum)
	{
		ans = __gcd(ans , s.Y);
	}
	printf("%lld\n", ans);

  return;
}


signed main()
{
	scanf("%d", &T);
  while(T--) solve();
  return 0;
}