#include <bits/stdc++.h>

using namespace std;
#define pb push_back

typedef long long ll;


int n, k;
const int maxn = 16;
const ll MOD = 1e9+7;
ll a[maxn][maxn];
ll dp[1<<maxn];
ll val[1<<maxn];

//inline void add(ll& a, ll b){ a+=b; a%=MOD;};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n; int S = (1<<n)-1;
  for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) cin >> a[i][j];

  for (int x = 0; x <= S; x++)
  {
    val[x] = 0ll;
    for(int i = 0; i < n; i++)for(int j = i+1; j < n; j++)
    if(((x>>i)&1) && ((x>>j)&1))  val[x] += a[i][j];
  }

  for (int x = 0; x <= S; x++)
  {
    dp[x] = val[x];
    for (int s = x; s; s=(s-1)&x)
    { //s = x'
        dp[x] = max(dp[x], dp[s]+dp[s^x]);
    }
  }
  //for (int x = 0; x <= S; x++) cout << dp[x] << endl;
  cout << dp[S] << endl;

  return 0;
}
