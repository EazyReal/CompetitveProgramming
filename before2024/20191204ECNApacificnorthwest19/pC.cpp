#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;
ll dp[1005][1005];
ll MOD = 998244353;
ll a[1005];

map<ll, ll> cnt;

int main()
{
  cin >> n >> k;
  ll tmp;
  for(int i = 0; i < n; i++)
  {
     cin >> tmp;
     auto it = cnt.find(tmp);
     if(it == cnt.end()) cnt[tmp] = 0;
     cnt[tmp]++;
     dp[i][0] = 1;
  }

  dp[0][1] = cnt.begin()->second;
  int i = 1;
  auto it = cnt.begin();
  for(it++; it!=cnt.end(); it++, i++)for(int j = 1; j<=min(i+1,k); j++)
  {
    //cout<<i<<' '<<j<<'\n';
    dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]*it->second)%MOD;
  }
  // for(int i = 0; i < n; i++){
  //   for(int j= 0; j <=k; j++){
  //     cout<<dp[i][j]<<' ';
  //   }
  //   cout<<'\n';
  // }
  cout << dp[cnt.size()-1][k];
  return 0;
}
