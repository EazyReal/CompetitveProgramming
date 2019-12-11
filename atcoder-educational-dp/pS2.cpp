#include <bits/stdc++.h>

using namespace std;
#define pb push_back

typedef long long ll;

//dp[i][state][k], i:calc from figher to lower digit, state 0 <, state 1 = maxmimum, mod K = k
//ans = (dp[n-1][0][0] + dp[n-1][1][0] + MOD-1) % MOD

int n, k;
const int maxn = 1e4+5;
const int maxk = 100+5;
const ll MOD = 1e9+7;
ll dp[maxn][2][maxk]; //0: a[i] < s[i], 1: a[i] == s[i]

inline void add(ll& a, ll b){ a+=b; a%=MOD;};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  string s;
  cin >> s >> k;
  n = s.size();

  memset(dp, 0ll, sizeof(dp));
  for(int d = 0; d < int(s[0]-'0'); d++) dp[0][0][d%k] += 1ll;
  dp[0][1][int(s[0]-'0')%k] = 1ll;
  for(int i = 1; i < n; i++)
  {
    for(int ki = 0; ki < k; ki++)
    {
      //any a[i], before < , case 0
      for(int d = 0; d < 10; d++) add(dp[i][0][(ki+d)%k], dp[i-1][0][ki]);
      //a[i] < s[i], before = maximum, case 0
      for(int d = 0; d < int(s[i]-'0'); d++) add(dp[i][0][(ki+d)%k], dp[i-1][1][ki]);
      //a[i-1], before = maximum, case 1
      dp[i][1][(ki+int(s[i]-'0'))%k] = dp[i-1][1][ki];
    }
  }
  ll ans = (dp[n-1][0][0]+dp[n-1][1][0]-1ll+MOD)%MOD;//-1, 00000000 //WA, care -1ll when %MOD==0
  cout <<  ans << endl;

  return 0;
}
