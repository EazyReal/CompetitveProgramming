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
int T;
const int maxn = 2e5+7;
int n;
int a[3][4];

//check T
void solve()
{
  int k;
	cin >> k;
  if(k == 0) {cout << "1 1\n0\n"; return;}
  /*
  n = 3;
  cout << 3 << ' ' << 3 << endl;
  rep(i, 0, n)rep(j, 0, n) a[i][j] = k;
  int b = 1;
  while(b <= k) b <<= 1;
  b += (~k)&(b-1);
  a[1][1] = b;
  if(k == 0) a[1][1] = k;
  //cout << b << endl;
  rep(i, 0, n)
  {
    rep(j, 0, n) cout << a[i][j] << " \n"[j==n-1];
  }
  */
  cout << "3 4" << endl;
  int b = 1;
  int bb;
  while(b <= k) b <<= 1;
  bb = b << 1;
  int x = b+k;
  int nx = (~x)&(bb-1);
  int y = b+0;
  a[0][0] = a[2][0] = a[2][1] = a[2][2] =  bb|x;
  a[0][1] = a[0][2] = a[1][2] = a[2][3] = x;
  a[0][3] = a[1][1] = 0;
  a[1][0] = bb|nx;
  a[1][3] = y;
  
  rep(i, 0, 3)
  {
    rep(j, 0, 4) cout << a[i][j] << " \n"[j==4-1];
  }
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
