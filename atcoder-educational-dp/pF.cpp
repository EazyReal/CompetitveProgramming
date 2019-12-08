#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int T, n;
const int maxl = 3000+5;
int dp[maxl][maxl];
int path[maxl][maxl];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s, t;
  cin >> s >> t;

  //bug : init should cover all 0
  for(int i = 0; i <= max(s.size(), t.size()); i++) dp[0][i] = dp[i][0] = 0, path[0][i]=path[i][0]=-1;

  for(int i = 1; i <= s.size(); i++)for(int j = 1; j <= t.size(); j++)
  {
    if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1]+1, path[i][j] = 0;
    else if(dp[i-1][j] > dp[i][j-1]) dp[i][j] = dp[i-1][j], path[i][j] = 1;
    else dp[i][j] = dp[i][j-1], path[i][j] = 2;
  }
  //cout << dp[s.size()][t.size()];
  char ans[maxl];
  int x = s.size(), y = t.size();
  int cur = dp[x][y];
  ans[cur--] = '\0';
  while(path[x][y] != -1)
  {
    if(path[x][y] == 0) x--, y--,ans[cur--] = s[x];
    else if(path[x][y] == 1) x--;
    else y--;
  }
  cout << ans;

  return 0;
}
