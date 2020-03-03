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

//mt19937 mrand(random_device{}());
//const ll mod=1e9+7;
//int rnd(int x) { return mrand() % x;}
//ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//INT_MAX, ULLONG_MAX, LLONG_MAX or numeric_limits<int>::min()

//------------------------------------------------------------------------//
int T;
const int maxn = 2e4+5;
int n, m, k;
int a[55][maxn];
int dp[55][maxn];
int pre[55][maxn];

inline int seg(int i1, int i2, int jl, int jr)
{
  return pre[i1][jr]-pre[i1][jl] + pre[i2][jr]-pre[i2][jl];
}

void solve()
{
  cin >> n >> m >> k;
  rep(i, 1, n+1) a[i][0] = 0, a[i][m+1] = 0;
  rep(i, 1, n+1)rep(j, 1, m+1) cin >> a[i][j], pre[i][j] = pre[i][j-1] + a[i][j];
  rep(j, 1, m+1) a[n+1][j] = 0;

  rep(j, 1, m-k+2) dp[1][j] = seg(1, 2, j-1, j+k-1);
  cout << endl; rep(j, 1, m-k+2) cout << dp[1][j] << " \n"[j==m-k+1];
  rep(i, 2, n+1) rep(j, 1, m-k+2)
  {
    
  }
  return;
}


signed main()
{
  fastIO();
  //cin >> T;
  T = 1;
  while(T--) solve();
  return 0;
}
