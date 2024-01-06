#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define repinv(i, st, n) for (int i = ((n)-1); i >= (st); --i)

#define debug(x) std::cout << #x << ": " << x << endl
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fileIO(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

mt19937 mrand(random_device{}());
const ll mod=1e9+7;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

//------------------------------------------------------------------------//

int T;
ll n; //meaningful max n is maxm * maxai = 10^14, maxn 10^18
//bits <= 70;(65)
int m;
const int maxm = 1e5+5;
const int maxb = 63;
ll a[maxm];
ll bits[maxb];

signed main()
{
  fastIO();
  cin >> T;
  while(T--)
  {
    cin >> n >> m;
    ll sum = 0ll;
    rep(bi, 0, maxb) bits[bi] = 0ll;//...
    rep(i, 0, m)
    {
      cin >> a[i];
      sum += a[i];
      rep(bi, 0, maxb)if(a[i]&(1ll<<bi)) {bits[bi]++;}
    }
    if(sum < n || n > ll(1e14)) {cout << -1 << endl; continue;}
    ll ans = 0ll;
    ll below = 0ll;
    rep(i, 0, maxb)
    {
      ll val = (1ll<<i);
      below += bits[i]*val;
      if(val&n)
      {
        //debug(val);
        if(below >= val) below-=val;
        else{
          rep(j, i, maxb)if(bits[j])
          {
            bits[j]--;
            rep(k, i+1, j) bits[k]++;
            below += val;//2val is below but 1val spent
            ans += j-i;
            //cur i extra +1-1;
            break;
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
