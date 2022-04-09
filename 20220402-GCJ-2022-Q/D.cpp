#include <bits/stdc++.h>

#define int long long
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

using namespace std;

int n;

const int maxn = 1e5 + 5;

int val[maxn];
int p[maxn];
// the sum is s[x]-m[x]+r[x]
// the gain is r[x] - m[x]
int ans;

int dfs(int u, vector<vector<int>> &cs)
{
    if (cs[u].size() == 0)
        return val[u];
    int m = 1e9 + 5;
    for (int v : cs[u])
    {
        int vv = dfs(v, cs);
        ans += vv;
        m = min(m, vv);
    }
    ans -= m;
    return max(m, val[u]);
}

void solve(int tc)
{
    cin >> n;
    vector<vector<int>> cs(n + 1);
    rep(i, 1, n + 1) cin >> val[i];
    rep(i, 1, n + 1) cin >> p[i], cs[p[i]].push_back(i);
    cout << "Case #" << tc << ": ";
    ans = 0;
    ans += dfs(0, cs);
    cout << ans << endl;
    return;
}

signed main()
{
    fastIO();
    int T = 1;
    cin >> T; // this
    rep(tc, 1, T + 1)
    {
        solve(tc);
    }
    return 0;
}
