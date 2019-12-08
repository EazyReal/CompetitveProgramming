#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, k;
const ll maxn = 100+5;
const ll maxk = (1e5+5)*2;
ll MOD = 1e9+7;
ll a[maxn];
bool dp[maxk];

int main()
{
  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> a[i];
  dp[0] = 0;
  for(int i = 0; i <= k; i++)for(int j = 0; j < n; j++)
    dp[i+a[j]] |= (dp[i]==0);
  cout << (dp[k]?"First":"Second") << endl;
  return 0;
}
