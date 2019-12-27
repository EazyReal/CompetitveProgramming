#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll T;
ll n, m;
const ll maxn = 1000000+5;
const ll maxa = 1000000+5;
const ll MOD = 998244353;
ll k[maxn];
//ll inv[MOD+5];
vector<ll> A[maxn];
ll cnt[maxa];
set<ll> toys;
vector<ll> terms;

ll modInverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0ll, x = 1ll;

    if (m == 1ll)
      return 0ll;

    while (a > 1ll)
    {
        // q is quotient
        ll q = a / m;
        ll t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0ll)
       x += m0;

    return x;
}


int main()
{
  ios::sync_with_stdio(0);
  //inv[1] = 1;
  //for(ll i = 2; i < MOD; ++i) inv[i] = (MOD - (MOD/i) * inv[MOD%i] %MOD) %MOD;

  memset(cnt, 0ll, sizeof(cnt));
  cin >> n;
  for(ll i = 0; i < n; i++)
  {
    cin >> k[i];
    ll tmp;
    for(ll j = 0; j < k[i]; j++)
    {
      cin >> tmp;
      A[i].push_back(tmp);
      cnt[tmp]++;
      toys.insert(tmp);
    }
  }
  ll terms_product = 1ll;
  //ll toyinv = modInverse(toys.size(), MOD);
  for(ll i = 0; i < n; i++)for(ll j = 0; j < k[i]; j++)
  {
    ll term = (k[i]*modInverse(cnt[A[i][j]], MOD))%MOD; //misuse, btw can speed up by preprossing 
    terms.push_back(term);
    terms_product = (terms_product*term)%MOD;
  }
  ll ans = modInverse((n*n)%MOD, MOD); //misuse
  ll x = 0ll;
  for(auto term : terms)
  {
    x = (x + (terms_product*modInverse(term, MOD))%MOD)%MOD;
  }
  ans = (ans*x)%MOD;
  ans = (ans*modInverse(terms_product, MOD))%MOD;
  cout << ans << endl;
  return 0;
}
