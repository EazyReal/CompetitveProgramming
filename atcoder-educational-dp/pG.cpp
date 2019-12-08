#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define pb push_back

int T, n, m;
const int maxn = 100000+5;
const int maxm = 100000+5;

ll dp[maxn+5]; //minimal weight for val
ll ind[maxn+5];
vector<int> G[maxn];
vector<int> Ginv[maxn];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;

  int u, v;
  for(int i = 1; i <= n; i++) G[i].clear(), Ginv[i].clear(), ind[i] = 0;
  for(int i = 0; i < m; i++)
  {
    cin >> u >> v;
    G[u].pb(v);
    Ginv[v].pb(u);
    ind[v]++;
  }
  queue<int> q;
  memset(dp, 0, sizeof(dp));
  for(int i = 1; i <=n; i++) if(ind[i] == 0) q.push(i);
  while(!q.empty())
  {
    int x = q.front(); q.pop();
    for(int i = 0; i < G[x].size(); i++)
    {
      int y = G[x][i];
      dp[y] = max(dp[y], dp[x]+1ll);
      if(--ind[y] == 0)q.push(y);
    }
  }
  ll ans = 0;
  for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);
  cout << ans << endl;

  return 0;
}
