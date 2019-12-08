#include <bits/stdc++.h>

using namespace std;
#define pb push_back

typedef long long ll;

//forget that max is with property abc = (ab)c = a(bc)
//can use Binary Index Tree to solve for 0-h[i]'s max val in logn

int n;
const int maxn = 2e5+5;
const int maxa = 1e9;
ll MOD = 1e9+7;
ll a[maxn];
int h[maxn];
ll dp[maxn];
ll bit[maxn*2];//actually maxh = maxn

inline int lowbit(int x){return  x&(-x);}

void update(int k, ll val)
{
 for(;k<=n;k+=lowbit(k)) bit[k] = max(bit[k], val);
}

ll query(int k)
{
  ll ret = 0ll;
  for(;k>0;k-=lowbit(k)) ret = max(ret, bit[k]);
  return ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> h[i];
  for(int i = 0; i < n; i++) cin >> a[i];
  memset(bit, 0ll, sizeof(bit)); //reset = 0 maximum
  for(int i = 0; i < n; i++)
  {
    dp[i] = query(h[i]) + a[i];
    update(h[i], dp[i]);
  }
  ll maxv = 0;
  for(int i = 0; i < n; i++) maxv = max(maxv, dp[i]);
  cout << maxv << endl;

  return 0;
}
