// #include <bits/stdc++.h>
#include <string>
#include <iostream>

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
const int maxn = 2e5 + 7;
int n;
// ll a[maxn];

// check T
void solve(int tc)
{
    string s;
    int n;
    cin >> n;
    cin >> s;
    if (n == 2)
    {
        cout << (s[1] > s[0] ? "Yes" : "No") << endl;
        return;
    }
    bool ok = 0;
    char start = s[0];
    for (auto c : s)
    {
        if (c > start)
        {
            cout << "Yes\n";
            return;
        }
    }
    // now the max is s[0]
    string pre;
    string last;
    int index = 0;
    for (auto c : s)
    {
        last += c;
        if (c == start || index == n - 1)
        {
            if (!pre.empty() && last > pre)
            {
                // cerr << last << " " << pre << endl;
                cout << "Yes\n";
                return;
            }
            else
            {
                pre += last;
                pre.pop_back(); // remove s
                last = start;
            }
        }
        index++;
    }
    cout << "No\n";
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
