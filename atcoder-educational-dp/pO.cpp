#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//this can AC
//but should notice that i = bitcount(s)
//learn the iterative method of subset dp

int n;
const ll maxn = 21+5;
ll MOD = 1e9+7;
bool a[maxn][maxn];
ll dp[maxn][1ll<<22];

ll dfs(int i, bitset<21> s) //now to choose, remaining
{
  ll ls = ll(s.to_ulong());
  if(dp[i][ls] != -1ll) return dp[i][ls];
  if(i == n) {assert(ls == 0ll); return 1ll;}
  if(ls==0ll) return 0ll;
  ll ret = 0ll;
  for(int j = 0; j < n; j++)
  if(a[i][j] && s.test(j))
  {
    s.reset(j);
    ret = (ret+dfs(i+1, s))%MOD;
    s.set(j);
  }
  return dp[i][ls] = ret;
}

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++)for(int j = 0; j < n; j++) cin >> a[i][j];
  bitset<21> u;
  for(int i = 0; i < n; i++) u.set(i);
  //cout << u << endl;
  memset(dp, -1ll, sizeof(dp));
  ll ans = dfs(0, u);
  cout << ans << endl;

  return 0;
}
