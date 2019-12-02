#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int T, n;
const int maxn = 2999+5;

double p[maxn];
double dp[maxn][maxn][maxn]; // dp[][1-cnt/2-cnt/3-cnt]
double a;
int cnt[4];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for(int i = 0; i < 4; i++) cnt[i] = 0;
  for(int i = 0; i < n; i++) cin >> a, cnt[a]++;
  for(int i = 0; i < cnt[3]; i++) for(int i = 0; i < cnt[2]; i++)
  for(int i = 0; i < cnt[3]; i++)

  cout << fixed << setprecision(10) <<  ans << endl;

  return 0;
}
