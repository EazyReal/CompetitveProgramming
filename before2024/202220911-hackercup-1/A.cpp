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
const int maxn = 2e5 + 7;

template <typename T>
pair<bool, bool> KMP(vector<T> &a, int n, vector<T> &b, int m) {
    vi lps(m);
    pair<bool, bool> ret = {0, 0};
    int len = 0;
    lps[0] = 0;
    for (int i = 1; i < m;) {
        if (b[i] == b[len]) {
            lps[i++] = ++len;
        }
        else {
            if (len > 0)
                len = lps[len-1];
            else
                lps[i++] = 0;
        }
    }
    for(int i = 0, j = 0; i < n;)
    {
        while(i < n && j < m && a[i] == b[j]) 
            i++, j++;
        if (j == m)
        {
            if(i-m == 0 || i-m == m) ret.X = 1; // has exact match
            else ret.Y = 1; // has non-exact match (shifted)
        }
        if (i == n)
            break;
        if (j != 0)
            j = lps[j-1];
        else
            i++;
    }
    return ret;
}

// check T
void solve(int tc)
{
    int n, k;
    cin >> n >> k;
    vi a(2*n), b(n);
    rep(i, 0, n)
    {
        cin >> a[i];
        a[i+n] = a[i];
    }
    rep(i, 0, n) cin >> b[i];
    pair<bool, bool> kmp = KMP(a, 2*n, b, n);
    // debug(kmp.X);
    // debug(kmp.Y);
    bool ok = 0;
    if(kmp.X == 1)
    {
        ok |= k%2==0;
        ok |= n>2 && k>1;
    }
    if(kmp.Y == 1)
    {
        ok |= n==2 && (k%2==1);
        ok |= n>2 && k>0; //if not and n>2
    }
    cout << "Case #" << tc << ": " << (ok ? "YES": "NO") << endl;
    return;
}

// g++ -o out -std=c++11 A.cpp

signed main()
{
    fastIO();
    fileIO("consecutive_cuts_chapter_2_input.txt", "output.txt");
    T = 1;
    cin >> T; // this
    rep(tc, 1, T + 1)
    {
        solve(tc);
    }
    return 0;
}
