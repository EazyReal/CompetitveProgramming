#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define fastIO()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)

using vi = vector<int>;

//------------------------------------------------------------------------//
int lcs(vi &a, vi &b) {
  int n = a.size();
  int m = b.size();
  vector<vi> dp(n + 1, vi(m + 1, 0));
  rep(i, 1, n + 1) rep(j, 1, m + 1) {
    if (a[i - 1] == b[j - 1])
      dp[i][j] = dp[i - 1][j - 1] + 1;
    else
      dp[i][j] = max({dp[i - 1][j], dp[i][j - 1]});
  }
  return dp[n][m];
}

// check T
void solve() {
  int n;
  cin >> n;
  vi a;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (!a.size() || a.back() != x) a.pb(x);
  }
  vi ra(a);
  reverse(all(ra));
  cout << a.size() - 1 - (lcs(a, ra) - 1) / 2 << endl;
  return;
}

// g++ -o out -std=c++11 A.cpp

signed main() {
  fastIO();
  solve();
  return 0;
}
