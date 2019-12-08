#include <bits/stdc++.h>

using namespace std;
#define pb push_back

typedef long long ll;

int n;
const int maxn = 1e5+5;
ll MOD = 1e9+7;
vector<int> G[maxn];
ll dp[2][maxn];

ll dfs(bool c, int u, int p) //
{
  if(dp[c][u] != -1ll) return dp[c][u];
  ll ret = 1ll;
  for(auto v: G[u])if(v!=p)
  {
    if(c) ret = (ret*dfs(0, v, u))%MOD;
    else ret = (ret*(dfs(0, v, u)+dfs(1, v, u)))%MOD; //care overflow
  }
  return dp[c][u] = ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n;
  int tu, tv;
  for(int i = 0; i < n-1; i++)
  {
    cin >> tu >> tv;
    G[tu].pb(tv);
    G[tv].pb(tu);
  }
  G[0].pb(1);
  memset(dp, -1ll, sizeof(dp));
  cout << dfs(0, 0, -1) << endl; //color not black in psuedo root nxt to node 1

  return 0;
}
