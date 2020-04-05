#include <bits/stdc++.h>
#define LOCAL
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
int T;
const int maxN = 4e6+7;
int n, m;
int N, M;
int a[maxN];
vector<int> ans;

#define pr (x>>1)
#define lc (x<<1)
#define rc (x<<1|1)
#define mc a[lc]>a[rc]?lc:rc

bool ok(int x)
{
  if(a[x] == 0) return 0;
  while(a[mc]) x = mc;
  return x >= M;
}

void pull(int x)
{
  while(a[mc]) x = mc, a[pr] = a[x];
  a[x] = 0;
}

//check T
void solve()
{
  ans.clear();
	cin >> n >> m;
  N = 1<<n;
  M = 1<<m;
  rep(i, 1, N) cin >> a[i];
  rep(i, N, N<<1) a[i] = 0; //WA on 66 or TLE
  ll sum = 0;
  rep(i, 1, M)
  {
    while(ok(i)) {ans.pb(i); pull(i);}
    sum += a[i];
  }
  cout << sum << endl;
  rep(i, 0, ans.size()) cout << ans[i] << " \n"[i==ans.size()-1];
  return;
}


signed main()
{
  fastIO();
  T = 1;
  cin >> T; //this
  while(T--) solve();
  return 0;
}
