#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int T, n;
const int maxn = 100;
const int maxv = 1000;
const int maxw = 1000000000;

const ll INF = 1ll<<60;

ll dp[maxn+5][maxv*maxn+5]; //minimal weight for val
ll W;
ll w[maxn];
ll v[maxn];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> W;
  for(int i = 0; i < n; i++) cin >> w[i] >> v[i];
  int maxj = maxv*n+1;
  for(int i = 0; i < n; i++) for(int j = 0; j < maxj; j++) dp[i][j] = INF;
  dp[0][v[0]] = w[0];
  dp[0][0] = 0ll;
  for(int i = 1; i < n; i++)
  {
    dp[i][0] = 0;
    for(int j = 1; j < maxj; j++)
    {
      dp[i][j] = dp[i-1][j];//bug
      if(v[i]<=j) dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]]+w[i]);
    }
  }
  ll ans = 0;
  for(int j = 0; j < maxj; j++)
  {
    //if(dp[n-1][j] != INF) cout << j << ' ' <<dp[n-1][j] << endl;
    if(dp[n-1][j] <= W) ans = j;
  }
  cout << ans << endl;
  //cout << dp[n-1][30];
  return 0;
}
