#include <bits/stdc++.h>
#define LOCAL
using namespace std;

#define int ll

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
const int maxn = 2e5 + 7;
int n;

int get1(int r, int x)
{
    int L = 0, R = r + 5, M;
    while (L + 1 < R)
    {
        M = (L + R) / 2;
        if (round(sqrt(M * M + x * x)) <= r)
            L = M;
        else
            R = M;
    }
    return L + 1;
}

int get2(int R, int x)
{
    unordered_set<int> s;
    rep(r, 0, R + 1)
    {
        int y = round(sqrt(r * r - x * x));
        y = abs(y);
        debug(y);
        s.insert(y);
    }
    return s.size();
}

int c1(int R)
{
    int ret = 0;
    rep(x, 0, R + 1) ret += get1(R, x);
    return ret;
}

int c2(int R)
{
    set<pair<int, int>> s;
    rep(r, 0, R + 1) rep(x, 0, R + 1)
    {
        int y = round(sqrt(r * r - x * x));
        if (y >= 0)
        {
            s.insert({x, y});
            s.insert({y, x});
        }
    }
    return s.size();
}

// void solve(int tc)
// {
//     cout << get1(2, 0) << endl;
//     cout << get1(2, 1) << endl;
//     cout << get1(2, 2) << endl;
//     cout << get1(2, 3) << endl;
// }

// check T
void solve(int tc)
{
    int R;
    cin >> R;
    int ans = 0;
    // debug(get1(4, 2));
    // debug(c1(R));
    // debug(c2(R));
    ans += c1(R) - c2(R);
    cout << "Case #" << tc << ": " << ans * 4 << endl;
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
