#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, k;
const ll maxn = 3000+5;
const ll maxk = 1e9+5;
ll MOD = 1e9+7;
ll a[maxn];
ll sum[maxn];
ll dp[maxn][maxn];

int main()
{
  cin >> n;
  a[0] = sum[0] = 0ll;
  for(int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i-1] + a[i], dp[i][i] = a[i];

  for(int l = 1; l < n; l++) for(int s = 1; s+l <= n; s++) // 1 is length - 1
  {
    int r = s+l;
    dp[s][r] = max(sum[r]-sum[s-1]-dp[s+1][r], sum[r]-sum[s-1]-dp[s][r-1]);
    //cout << dp[s][r] << endl;
  }
  cout << (2*dp[1][n])-sum[n] << endl; //X-Y not X
  return 0;
}
