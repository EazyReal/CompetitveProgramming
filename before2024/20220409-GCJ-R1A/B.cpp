#include <bits/stdc++.h>
#define LOCAL
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
#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define fileIO(in, out)      \
    freopen(in, "r", stdin); \
    freopen(out, "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

// mt19937 mrand(random_device{}());
// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 7;
// int rnd(int x) { return mrand() % x;}
ll powmod(ll a, ll b)
{
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
pii operator+(const pii &x, const pii &y) { return mp(x.X + y.X, x.Y + y.Y); }
pii operator-(const pii &x, const pii &y) { return mp(x.X - y.X, x.Y - y.Y); }

//------------------------------------------------------------------------//

int T;
const int maxn = 2e5 + 7;
int n;
// ll a[maxn];

// check T
void solve(int tc)
{
    cin >> n;
    vi A, B;
    rep(i, 7, 30)
    {
        int a = 1 << i;
        cout << a << " ";
        A.pb(a);
    }
    rep(i, 1, n - (30 - 7) + 1)
    {
        cout << i << " ";
        A.pb(i);
    }
    cout << endl;
    assert(A.size() == n);
    rep(i, 0, n)
    {
        int b;
        cin >> b;
        B.pb(b);
    }
    sort(all(A));
    reverse(all(A));
    vi ans[2];
    ll delta = 0;
    auto f = [&](int x)
    {
        if (delta < 0)
        {
            delta += x;
            ans[0].pb(x);
        }
        else
        {
            delta -= x;
            ans[1].pb(x);
        }
    };
    for (int &i : B)
        f(i);
    for (int &i : A)
        f(i);
    assert(delta == 0);
    for (int &i : ans[0])
        cout << i << " ";
    cout << endl;
    return;
}

// g++ -o out -std=c++11 A.cpp

signed main()
{
    fastIO();
    T = 1;
    cin >> T; // this
    rep(tc, 1, T + 1)
    {
        solve(tc);
    }
    return 0;
}
