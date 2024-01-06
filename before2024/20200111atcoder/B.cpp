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
const int maxn = 1e5+5;
const ll MOD = 1e9+7;
ll x[maxn];
ll a[maxn];
ll e[maxn];
ll fac[maxn];
ll inv[maxn];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    inv[1] = 1ll;
    for(int i = 2; i < maxn; ++i) inv[i] = (MOD - (MOD/i) * inv[MOD%i] % MOD) % MOD, assert(inv[i]*i%MOD==1);
    cin >> n;

    fac[0] = 1ll;
    rep(i, 0, n) cin >> x[i], fac[i+1] = (fac[i]*(i+1)%MOD)%MOD;
    rep(i, 1, n) a[i] = x[i]-x[i-1];

    e[1] = 1ll;
    ll sum = (e[1]*a[1])%MOD;
    /*
    rep(i, 2, n)
    {
      e[i] = (1+(((((i-1)*inv[i])%MOD)*e[i-1])%MOD))%MOD;
      sum += (e[i]*a[i])%MOD;
    }
    */
    //cout << inv[2] <<endl;
    rep(i, 2, n)
    {
      e[i] = ((ll(i)+1ll)%MOD*inv[2])%MOD;
      sum += (e[i]*a[i])%MOD;
      sum%=MOD;
    }

    sum = (sum*fac[n-1])%MOD;
    cout << sum << endl;

    return 0;
}

/*
12
161735902 211047202 430302156 450968417 628894325 707723857 731963982 822804784 880895728 923078537 971407775 982631932
750927044
*/
