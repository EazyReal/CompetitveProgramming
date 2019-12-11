#include <bits/stdc++.h>

using namespace std;
#define pb push_back

typedef long long ll;



int n, k;
const int maxn = 1e4+5;
const int maxk = 100+5;
const ll MOD = 1e9+7;
ll dp[maxn][2][maxk]; //0: a[i] < s[i], 1: a[i] == s[i]

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  string s;
  cin >> s >> k;
  n = s.size();

  memset(dp, 0ll, sizeof(dp));
  cout << "s is " << s << endl;
  cout << "s[0] is " << s[0] << endl;
  for(int d = 0; d <= int(s[0]-'0'); d++) dp[0][2][d%k] += 1ll; // 2: a[i] < s[i]
  for(int d = 1; d < 10; d++) dp[0][1][d%k] += 1ll; // 1: no limit and a[i] != 0
  dp[0][0][0] = 1ll; // 0 : no limit and a[i] == 0
  for(int i = 1; i < n; i++)
  {
    for(int ki = 0; ki < k; ki++)
    {
      //d+ki-1 = ki mod k
      //ki-1 = ki-d mod k
      dp[i][0][ki] = (dp[i-1][0][ki]+dp[i-1][1][ki])%MOD;
      dp[i][1][ki] = dp[i][2][ki] = 0ll;
      for(int d = 1; d < int(s[i]-'0'); d++) //not biggest a[i] < s[i]
      {
        dp[i][2][ki] = (dp[i][2][ki] + dp[i-1][0][(ki-d+k)%k] + dp[i-1][1][(ki-d+k)%k])%MOD;
      }
      for(int d = 1; d < 10; d++) //any
      {
        dp[i][1][ki] = (dp[i][1][ki] + dp[i-1][2][(ki-d+k)%k])%MOD;
      }

    }
  }

  for(int i = 0; i < n; i++, cout << endl)for(int ki = 0; ki < k; ki++)
  cout << dp[i][ki] << ' ';

  ll ans = 0ll;
  for(int i = 0; i < n; i++) ans = (ans + dp[i][0])%MOD;
  cout << ans << endl;

  return 0;
}
