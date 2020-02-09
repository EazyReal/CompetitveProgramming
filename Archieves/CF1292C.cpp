//CF1292C
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define debug(x) std::cout << #x << ": " << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int T, n;
const int maxn = 3000+5;
vector<int> G[maxn];
ll dp[maxn][maxn];
ll sz[maxn][maxn];
int p[maxn][maxn];

ll dfs_pre(int u, int f, int s)//now , from, source
{
  ll &ret = sz[s][u];
  ret = 1ll;
  p[s][u] = f;
  for(int& v : G[u])if(v != f) ret += dfs_pre(v, u, s);
  return ret;
}

ll dfs(int s, int t)
{
  ll &ret = dp[s][t];
  if(s == t || !s || !t) return ret = 0ll;
  if(~ret) return ret;
  ret = 0ll;
  //last is t side or s side
  //use p[s][t] to find path
  ret = max(dfs(p[s][t], s), dfs(p[t][s], t)) + sz[s][t]*sz[t][s];
  return ret;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in", "r", stdin);
    cin >> n;
    int u, v;
    rep(i, 0, n-1)
    {
      cin >> u >> v; //1-indexed
      G[u].pb(v);
      G[v].pb(u);
    }
    rep(i, 1, n+1) dfs_pre(i, 0, i); //use 0 to deal with edge case
    memset(dp, -1ll, sizeof(dp));
    ll ans = 0;
    rep(s, 1, n+1) rep(t, s+1, n+1)
    {
      ans = max(ans, dfs(s, t));
    }

    cout << ans << endl;

    return 0;
}
