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
const ll mod=1e9+7;
//int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//INT_MAX, ULLONG_MAX, LLONG_MAX or numeric_limits<int>::min()

//------------------------------------------------------------------------//
int T;
const int maxn = 1e3+5;
const int maxv = 2e5+5; //max(H+W)
int h, w, n;

ll inv[maxv], fac[maxv], facinv[maxv];


//https://cp-algorithms.com/algebra/module-inverse.html
void build(int h, int w) //build factorization and inverse factorization O(w+h)
{
  fac[0] = facinv[0] = 1;
  inv[1] = 1; fac[1] = 1; facinv[1] = 1;
  rep(i, 2, h+w+5)
  {
    fac[i] = fac[i-1]*i%mod;
    inv[i] = (mod - (mod/i) * inv[mod%i] % mod) % mod; //mem this, or derive from def of mid
    facinv[i] = facinv[i-1]*inv[i]%mod; //type i -> i-1
  }
}

ll calc(ll n, ll m) //C(n+m, m)
{
  return fac[n+m]*facinv[n]%mod*facinv[m]%mod;
}

void solve()
{
   cin >> h >> w >> n;
   build(h, w);
   //use a^(mod-2) can do a inverse too (O(log(mod)))
   //or extended gcd
   vector<pll> ps;
   ll xi, yi;
   rep(i, 0, n)
   {
     cin >> xi >> yi;
     ps.pb(mp(xi, yi));
   }
   ps.pb(mp(ll(h), ll(w)));

   function<bool(pll&, pll&)> cmp = [&](pll &a, pll &b)
   {
     return a.X+a.Y < b.X+b.Y;
   };
   sort(all(ps), cmp);

   vector<ll> dp(n+1);
   rep(i, 0, n+1)
   {
     dp[i] = calc(ps[i].X-1, ps[i].Y-1);
     //debug(dp[i]);
     rep(j, 0, i) if(ps[j].X <= ps[i].X && ps[j].Y <= ps[i].Y)
     {
       dp[i] -= dp[j] * calc(ps[i].X-ps[j].X, ps[i].Y-ps[j].Y) % mod; 
       dp[i] = (dp[i]%mod+mod)%mod;
     }
   }
   cout << dp[n] << endl;

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
