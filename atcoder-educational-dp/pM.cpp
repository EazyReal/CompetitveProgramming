#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, k;
const ll maxk = 1e5+5;
ll dp[2][maxk]; // use former i to distribute k's ways
ll s[2][maxk]; //prefix sum dp
ll MOD = 1e9+7;

int main()
{
  cin >> n >> k;
  for(ll i = 0ll; i <= k; i++) s[0][i]=s[1][i]=0ll;
  ll tmp; bool c = 0;
  //first
  cin >> tmp;
  dp[c][0ll] = 1ll, s[c][0ll] = 1ll;
  //not k bugged
  for(ll i = 1ll; i <= k; i++) {dp[c][i] = (i<=tmp)?1ll:0ll; s[c][i] = (s[c][i-1ll] + dp[c][i])%MOD;}//no mod
  //other
  for(ll i = 2ll; i <= n; i++)
  {
    //for(int i = 0; i <= k; i++) cout << dp[c][i] << endl;
    //cout << "nxt" << endl;
    cin >> tmp;
    //dp[c^1][0ll] = i; bugged
    //s[c^1][0ll] = i; bugged
    for(ll j = 0ll; j <= k; j++) //to distribute
    {
      ll canleft = j - tmp; //to distribute - now can distibute
      if(canleft> 0ll) dp[c^1][j] = ((s[c][j]-s[c][canleft-1ll])+MOD)%MOD; //dp[mark] + dp[mark+1] + ... + dp[j]
      else dp[c^1][j] = s[c][j];
      s[c^1][j] = (s[c^1][j-1ll]+dp[c^1][j])%MOD;
    /*
      dp[c^1][j] = 0;
      for(ll x = 0; x <= min(tmp,j) ; x++)
        dp[c^1][j] = (dp[c^1][j] + dp[c][j-x])%MOD;
    */
    }
    c ^= 1;
  }
  cout << dp[c][k] << endl;
  return 0;
}
