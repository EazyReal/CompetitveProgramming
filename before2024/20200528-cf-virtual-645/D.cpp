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
#define int ll
int T;
const int maxn = 2e5+7;
int n;
ll a[maxn*2];

int x;

//check T
void solve()
{
  cin >> n >> x;
  rep(i, 0, n) cin >> a[i];
  int maxv = 0;
  rep(i, 0, n)
  {
    a[n+i] = a[i];
    maxv = max(maxv, a[i]);
  }
  if(maxv >= x) {
    cout << (maxv + maxv -x+1)*(x)/2 << endl;
    return ;
  }
  n = 2*n;
  
  int l = 0, r = l;
  int s = a[0];
  int ans = 0;
  int val = (a[0]+1)*a[0]/2;
  while(l <= r && r < n && l < n)
  {
    while(r+1 < n && s + a[r+1] <= x) r++, s += a[r], val += (a[r]+1)*a[r]/2;
    int part;
    if(l > 0) part = (a[l-1] + a[l-1] - (x-s-1)) * (x-s) / 2;
    debug(l);debug(r); debug(part); debug(val);
    ans = max(ans, val + part);
    r++, s += a[r], val += (a[r]+1)*a[r]/2;
    if(l < r  && s > x) s-=a[l], val -= ((a[l]+1)*a[l]/2-part), l++;
    while(l < r  && s > x) s-=a[l], val -= ((a[l]+1)*a[l]/2-part), l++;
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
