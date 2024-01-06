#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  if (k > 4 * n * m - 2 * n - 2 * m) cout << "NO\n";
  else {
    cout << "YES\n";
    vector<pair<int, string>> ans;

    auto act = [&](int cnt, string_view sv) {
      int tot = min<int>(cnt * sv.size(), k);
      if (int cnt = tot / sv.size())
        ans.emplace_back(cnt, sv);
      if (int rem = tot % sv.size())
        ans.emplace_back(1, sv.substr(0, rem));
      k -= tot;
    };

    act(m-1, "R");
    act(m-1, "L");
    for (int i = 0; i < n-1; i++) {
      act(1, "D");
      act(m-1, "RUD");
      act(m-1, "L");
    }
    act(n-1, "U");

    cout << ans.size() << '\n';
    for (const auto& [a, b] : ans) {
      cout << a << ' ' << b << '\n';
    }
  }
  return 0;
}

//By Riatre, contest: Codeforces Round #619 (Div. 2), problem: (D) Time to Run, Accepted, #, Copy, hack it!
