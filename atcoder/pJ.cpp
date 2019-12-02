#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int T, n;
const int maxn = 300+5;

double p[maxn];
double dp[maxn][maxn][maxn]; // dp[1-cnt/2-cnt/3-cnt]
int cnt[4];

double dfs(int n, int i, int j, int k)
{
  if(dp[i][j][k]!=-1) return dp[i][j][k];
  double ans = double(n)/(i+j+k); //000 is not -1
  if(i>0) ans += (double(i)/(i+j+k))*dfs(n, i-1,j,k);
  if(j>0) ans += (double(j)/(i+j+k))*dfs(n, i+1,j-1,k);
  if(k>0) ans += (double(k)/(i+j+k))*dfs(n, i,j+1,k-1);
  return dp[i][j][k] = ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for(int i = 0; i < 4; i++) cnt[i] = 0;
  int a;
  for(int i = 0; i < n; i++) cin >> a, cnt[a]++;
  for(int i = 0; i < maxn; i++)for(int j = 0; j < maxn; j++)for(int k = 0; k < maxn; k++)
    dp[i][j][k] = -1;
  dp[0][0][0] = 0;
  double ans = dfs(n, cnt[1], cnt[2], cnt[3]);
  cout << fixed << setprecision(10) <<  ans << endl;

  return 0;
}
