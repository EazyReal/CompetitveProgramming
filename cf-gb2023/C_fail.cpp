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

// a o b e
// F -> a2 (0, -2) > b2 (0, 0) > ab (1, -1)
// S -> ab > b2 < a2

struct ArrayHasher {
  std::size_t operator()(const std::array<int, 3> &a) const {
    std::size_t h = 0;
    for (auto e : a) {
      // Combine hash values using a well-established technique
      h = std::hash<int>{}(e) + 0x9e3779b9 + (h << 6) + (h >> 2);
    }
    return h;
  }
};

// check T
void solve(int tc) {
  cin >> n;
  vi a(n);
  for (auto &x : a) cin >> x;
  // get unmatched
  auto dp = unordered_map<array<int, 3>, int, ArrayHasher>{};
  auto dfs = [&dp](auto self, int o, int e, int f) -> int {
    if (dp.contains({o, e, f})) return dp[{o, e, f}];
    if (o + e == 1) return 0;
    auto get_o2 = [&]() {
      return dp[{o, e, f}] = self(self, o - 2, e + 1, 1 - f);
    };
    auto get_e2 = [&]() { return dp[{o, e, f}] = self(self, o, e - 1, 1 - f); };
    auto get_oe = [&]() {
      return dp[{o, e, f}] = self(self, o, e - 1, 1 - f) + 1;
    };
    if (f == 1) {
      if (o >= 2)
        return get_o2();
      else if (e >= 2)
        return get_e2();
      else if (o >= 1 && e >= 1)
        return get_oe();
      else
        throw "impossible";
    } else {
      if (o >= 1 && e >= 1)
        get_oe();
      else if (e >= 2)
        return get_e2();
      else if (o >= 2)
        return get_o2();
      else
        throw "impossible";
    }
  };

  auto answer = vector<i64>(n);
  // pre_sum, n odd, n even
  accumulate(a.begin(), a.end(), array<i64, 3>{0, 0, 0},
             [&](auto acc, auto ele) {
               array<i64, 3> cur = {acc[0] + ele, acc[1] + (ele & 1),
                                    acc[2] + !(ele & 1)};
               answer.emplace_back(cur[0] - dfs(dfs, cur[1], cur[2], 1));
               return cur;
             });
  // cout << "Case #" << tc << ": ";
  for (auto x : answer) cout << x << " ";
  cout << endl;
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
