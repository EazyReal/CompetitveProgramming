#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, k;
const ll maxn = 400+5;
const ll maxa = 1e9+5;
const ll INF = 1LL << 60;
ll MOD = 1e9+7;
ll a[maxn];
ll sum[maxn];
ll dp[maxn][maxn];

int main()
{
  cin >> n;
  a[0] = sum[0] = 0ll;
  for(int i = 1; i <= n; i++) cin >> a[i], dp[i][i] = 0ll, sum[i]=sum[i-1]+a[i];

  for(int l = 1; l < n; l++) for(int s = 1; s+l <= n; s++) // 1 is length - 1
  {
    int r = s+l;
    dp[s][r] = INF;
    for(int k = s; k < r; k++) dp[s][r] = min(dp[s][r], dp[s][k]+dp[k+1][r]+sum[r]-sum[s-1]);
    //cout << dp[s][r] << endl;
  }
  cout << dp[1][n] << endl;
  //greedy will work, by switching should prove it
  return 0;
}
