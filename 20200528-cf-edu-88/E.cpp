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
const ll mod= 998244353;
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
const int maxn = 5e5+7;
int n, k;
//ll a[maxn];
int f[maxn];
int fi[maxn];

//check T
void solve()
{
  //after shower
  cin >> n >> k;

  //pre process
  f[0] = 1;
  rep(i, 1, n+1) f[i] = f[i-1]*i%mod;
  //rep(i, 1, n+1) fi[i] = powmod(f[i], mod-2);
  fi[n] = powmod(f[n], mod-2);
  repinv(i, 0, n) fi[i] = fi[i+1]*(i+1)%mod;

  //obs1: 1, arbitrary (all mod 1 is 0)
  //obs2: 2, 2x ... (reduce to 1 case) 
  //choose min => other doesnt matter when choose min*x, or not in solution
  int ans = 0;
  rep(i, 1, n+1)
  {
    int c = n/i; 
    if(c < k) break; // not enough all take 1
    ans += f[c-1]*fi[k-1]%mod*fi[c-k]%mod;
    ans %= mod;
  }
  cout << ans << endl;

  return;
}


signed main()
{
  fastIO();
  T = 1;
  //cin >> T; //this
  rep(tc, 1, T+1)
  {
    //cout << "Case #" << tc << ": ";
    solve();
  }
  return 0;
}
