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

#define int ll

int T, n;
int g, b;

signed main()
{
  fastIO();
  cin >> T;
  while(T--)
  {
    cin >> n >> g >> b;
    int n2 = n/2+(n%2);
    //debug(n2);
    int cycle = g+b;
    int ans = -1;
    if(n2 <= g) ans = n;
    else{
      int need_cycle = n2/g;
      int have_left = n2%g;
      if(have_left) ans = (need_cycle*cycle)+have_left;
      else ans = (need_cycle-1)*cycle+g;
      ans = max(ans, n);
    }
    cout << ans << endl;
  }
  return 0;
}
