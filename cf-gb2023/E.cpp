#include <bits/stdc++.h>
#define LOCAL
using namespace std;

#define X first
#define Y second
#define pb push_back
#define REP(i, st, n) for (auto i : views::iota(st, n))
#define PER(i, st, n) for (auto i : views::iota(st, n) | views::reverse)
#define MEM(a, b) memset(a, b, sizeof(a));
#ifdef LOCAL
#define debug(x) std::cerr << #x << ": " << x << endl
#else
#define debug(x) 860111
#endif
#define fastIO()               \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);            \
  cout.tie(nullptr)
#define fileIO(in, out)    \
  freopen(in, "r", stdin); \
  freopen(out, "w", stdout)

// type definition
using i64 = long long;
using u64 = unsigned long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

// randomness
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

// modular arithmetic
const i64 mod = 1e9 + 7;
i64 powmod(i64 a, i64 b) {
  i64 res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
i64 gcd(i64 a, i64 b) { return b ? gcd(b, a % b) : a; }

// coordinates
pii operator+(const pii &x, const pii &y) { return {x.X + y.X, x.Y + y.Y}; }
pii operator-(const pii &x, const pii &y) { return {x.X - y.X, x.Y - y.Y}; }

// extreme values
// INT_MAX, Ui64ONG_MAX, i64ONG_MAX or numeric_limits<int>::min()

//------------------------------------------------------------------------//
int T;
const int maxn = 2e5 + 7;
int n;

// check T
void solve(int tc) {
  // cin >> n; vi a(n); for(auto &x: a) cin >> x;
  cout << "Case #" << tc << ": ";
  return;
}

// g++ -o out -std=c++11 A.cpp
signed main() {
  fastIO();
  T = 1;
  cin >> T;  // this if the problem do not input number of testcases
  REP(tc, 0, T) { solve(tc); }
  return 0;
}
