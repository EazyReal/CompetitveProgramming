#include <bits/stdc++.h>

using namespace std;
#define pb push_back

typedef long long ll;

int n;
const int maxn = 2e5+5;
const int maxa = 1e9;
ll MOD = 1e9+7;
ll a[maxn];
int h[maxn];
ll dp[maxn];
int pos[maxn];


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> h[i];
  for(int i = 0; i < n; i++) cin >> a[i];
  set<int, greater<int> > s;
  for(int i = 0; i < n; i++)
  {
    auto it = s.lower_bound(h[i]);
    dp[i] = a[i];
    if(it != s.end()) dp[i] += dp[pos[*(s.lower_bound(h[i]))]];
    pos[h[i]] = i;
    s.insert(h[i]);
  }
  ll maxv = 0;
  for(int i = 0; i < n; i++) cout << dp[i] << endl, maxv = max(maxv, dp[i]);
  cout << maxv << endl;

  return 0;
}
