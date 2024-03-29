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
int n;
typedef pair<int, pll> Block;

#define w Y.X
#define s X
#define v Y.Y

//observation : can be sort with a.s + a.w as property, its meaning is compacity(carrying self+top)
void solve()
{
   cin >> n;
   vector<Block> bs(n);
   int maxs = 0;
   for(auto &bi:bs) cin >> bi.w >> bi.s >> bi.v, bi.s+=bi.w, maxs = max(maxs, bi.s);
   sort(all(bs));

   vector<ll> dp(maxs+1, 0ll);
   ll ans = 0ll;
   //i : from if choose x must be before choose y, judge from y to x
   //j : from big update to small update that no current i updated will be used this round
   rep(i, 0, n)
   repinv(si, 0, bs[i].s-bs[i].w+1) //extra use of current volume(eq = original meaning of solidity)
   {
     //for nxt to carry = si+bs[i].w
     dp[si+bs[i].w] = max(dp[si+bs[i].w], dp[si]+bs[i].v); //carry si more => dp[si] + bs[i].v (current)
     //cout << si << ' '; debug(dp[si+bs[i].w]);
     ans = max(ans, dp[si+bs[i].w]);
   }
   cout << ans << endl;
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
