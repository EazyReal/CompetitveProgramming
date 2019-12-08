#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int T, n;
const int maxn = 2999+5;

double p[maxn];
double dp[maxn][maxn];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin>>p[i];
  dp[0][0] = 1.0;
  for(int i = 1; i <= n; i++)for(int j = 0; j <= i; j++)
  {
    dp[i][j] = dp[i-1][j]*(1.0-p[i]);
    if(j>0) dp[i][j] += dp[i-1][j-1]*p[i];
  }
  double ans = 0.0;
  for(int i = n/2+1; i <= n; i++) ans += dp[n][i]; //n odd
  cout << fixed << setprecision(10) <<  ans << endl;

  return 0;
}
