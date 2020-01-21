#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define debug(x) std::cout << #x << ": " << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

ll n, m;
const ll MOD = 1e9+7;
const ll M = 60*200 + 60 + 5;

ll f[M], rf[M], inv[M];

ll C(ll n, ll k)
{
  if(n<k || n<0ll || k<0ll) return 0ll;
  return (f[n]*rf[k])%MOD*rf[n-k]%MOD; //MOD twice
}

ll calc(int avg)
{
  ll ret = 0ll;
  ll s = avg*(n-1);
  rep(i, 0, n) //the num of over maxf
  {
    ll term = C(n-1, i)*C(s+n-1-i*(m+1)-1, n-1-1)%MOD;
    if(i%2 == 1) term = (MOD-term)%MOD;
    ret += term;
    ret %= MOD;
  }
  return ret;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    f[0] = 1; rf[0] = 1;
    f[1] = 1; rf[1] = 1; inv[1] = 1;
    rep(i, 2, M)
    {
      f[i] = f[i-1]*i%MOD;
      inv[i] = (MOD-MOD/i)*inv[MOD%i]%MOD;
      rf[i] = rf[i-1]*inv[i]%MOD;
    }
    while(1)
    {
      cin >> n >> m;
      if(n == 0 && m == 0) break;
      ll res = 0;
      rep(i, 0, m+1)
      {
        res += calc(i);
        res %= MOD;
      }
      res = (res*n)%MOD;
      cout << res << endl;
    }
    return 0;
}
