#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int T, n, m;
const int maxn = 1000+5;
const ll MOD = 1e9+7;

bool a[maxn][maxn];
ll dp[maxn][maxn];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  char c;
  for(int i = 0; i < n; i++)for(int j = 0; j < m; j++) cin >> c, a[i][j] = (c =='#');
  //for(int i = 0; i < n; i++, cout<<endl)for(int j = 0; j < m; j++) cout<<a[i][j];
  dp[0][0] = 1;

  for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)
  {
    if(!i&&!j)continue; //=1
    dp[i][j] = 0;
    if(a[i][j]) continue;
    if(i > 0) dp[i][j] += dp[i-1][j], dp[i][j]%=MOD;
    if(j > 0) dp[i][j] += dp[i][j-1], dp[i][j]%=MOD;
  }
  cout << dp[n-1][m-1] << endl;
  return 0;
}
