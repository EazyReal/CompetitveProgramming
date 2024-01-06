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

int T, n;

ll a, m;

ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  return gcd(b, a%b);
}


ll solve(ll r, ll n) {
    vector<ll>p;
    p.clear();
    for(ll i = 2ll; i*i <= n; ++i) {
        if(n % i == 0ll) {
            p.pb(i);
            while(n % i == 0ll) n /= i;
        }
    }
    if(n > 1ll) p.pb(n); //n prime
    ll sum = 0ll;
    for(ll msk = 1ll; msk < (1ll<<p.size()); ++msk) {
        ll mult = 1ll, bits = 0ll;
        for(int i = 0; i < p.size(); ++i) {
            if(msk & (1ll<<i)) { //choose ith factor
                bits++;
                mult *= p[i];
            }
        }
        ll cur = r / mult;
        if(bits & 1ll) sum += cur;
        else sum -= cur;
    }
    return r - sum;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in", "r", stdin);
    cin >> T;
    while(T--)
    {
      cin >> a >> m;
      ll d = gcd(a, m);
      //debug(d);
      a /= d; m /= d;
      cout << solve(m, m) << endl; // no -
    }
    return 0;
}
