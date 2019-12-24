#include <bits/stdc++.h>

using namespace std;
#define pb push_back

typedef long long ll;

//O(n^2logn) atmost => try to build up some state and transition
//try to consider the first i numbers end with j(with j <= i)
//dp[i+1][j] = {
// if(s[i+1] == '>') sigma dp[i][j..i] (use j => all the front >= j +=1)
// else sigma dp[i][1...j-1]
//}
//O(n^3) => O(n^2) by prefix sum

int n, k;
string str;
const int maxn = 3000+5;
const ll MOD = 1e9+7;
ll dp[maxn][maxn];
ll s[maxn][maxn]; //no roll

inline void add(ll& a, ll b){ a+=b; a%=MOD;};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n;

  cin >> str;
  memset(dp, 0ll, sizeof(dp));
  dp[0][0] = s[0][0] = 0ll;
  dp[0][1] = s[0][1] = 1ll;
  for(int i = 2; i <= n; i++) s[0][i] = (s[0][i-1]+dp[0][i])%MOD;

  for(int i = 1; i <= n-1 ; i++)
  {
    s[i][0] = 0ll;
    for(int j = 1; j <= i+1; j++) //satisfy i ><, using 1-i+1
    {
      if(str[i-1] == '<') add(dp[i][j], s[i-1][j-1]); // dp[i-1][k], j< j
      else add(dp[i][j], s[i-1][i]-s[i-1][j-1]); // dp[i-1][k], j>= j
      s[i][j] = (s[i][j-1] + dp[i][j])%MOD;
    }
  }
  //for(int i = 0; i <= n-1 ; i++, cout << endl)for(int j = 1; j <= i+1; j++) cout << dp[i][j];
  //for(int j = 0; j <= 3; j++, cout<<endl) cout << s[j];

  ll sum = 0ll;
  for(int i = 1; i <= n; i++) add(sum, dp[n-1][i]);
  cout <<  sum << endl;

  return 0;
}
