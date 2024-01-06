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
// INT_MAX, ULLONG_MAX, LLONG_MAX or numeric_limits<int>::min()

//------------------------------------------------------------------------//
int T;

const ll M = 1e9+7;
void add(ll &a, ll b) {
    a = (a + b) % M;
}

// check T
void solve(int tc)
{
    int n, q;
    cin >> n;
    ll total = 0;
    ll sxy2 = 0; 
    ll sx = 0, sy = 0, sqx = 0, sqy = 0;
    rep(i, 0, n) {
        ll x, y;
        cin >> x >> y;
        add(sxy2, x * x % M);
        add(sxy2, y * y % M);
        add(sx, x);
        add(sy, y);
    }
    cin >> q;
    sxy2 = sxy2 * q % M;
    rep(i, 0, q) {
        ll x, y;
        cin >> x >> y;
        add(sxy2, x * x % M * n % M);
        add(sxy2, y * y % M * n % M);
        add(sqx, x);
        add(sqy, y);
    }
    add(total, sxy2);
    add(total, -2 * sx * sqx % M);
    add(total, -2 * sy * sqy % M);
    
    cout << "Case #" << tc << ": " << (total + M) % M << endl;
    return;
}

// g++ -o out -std=c++11 A.cpp

signed main()
{
    fastIO();
    fileIO("watering_well_chapter_2_input.txt", "output.txt");
    T = 1;
    cin >> T; // this
    rep(tc, 1, T + 1)
    {
        solve(tc);
    }
    return 0;
}
