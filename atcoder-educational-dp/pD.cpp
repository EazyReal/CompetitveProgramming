#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int T, n;
const int maxn = 100;
const int maxv = 1000000000;
const int maxw = 100000;

const ll INF = 1ll<<60;

ll dp[maxw+5]; //minimal weight for val
ll W;
ll w[maxn];
ll v[maxn];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> W;
  for(int i = 0; i < n; i++) cin >> w[i] >> v[i];
  dp[0] = 0;
  dp[w[0]] = v[0];
  for(int i = 1; i < n; i++) for(int j = W; j > -1; j--) if(w[i]<=j) dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
  ll V = 0;
  for(int j = W; j > -1; j--) V = max(V, dp[j]);
  cout << V << endl;
  return 0;
}
