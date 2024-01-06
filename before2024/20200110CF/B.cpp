#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (ll i = (st); i < (n); ++i)
#define debug(x) std::cout << #x << ": " << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

ll T, n;
const ll maxn = 1e5+5;
ll a[maxn];
bool flag;

ll maxCrossingSum(ll arr[], ll l, ll m, ll h)
{
    ll sum = 0;
    ll left_sum = INT_MIN;
    ll lidx, ridx;
    for (ll i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
        {
          left_sum = sum;
          lidx = i;
        }
    }
    sum = 0;
    ll right_sum = INT_MIN;
    for (ll i = m+1; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum) // use >
        {
          ridx = i;
          right_sum = sum;
        }
    }
    if(lidx == 0 && ridx == n-1) flag = 1;
    return left_sum + right_sum;
}

ll maxSubArraySum(ll arr[], ll l, ll h)
{
   if (l == h)
     return arr[l];
   ll m = (l + h)/2;
   ll ML = maxSubArraySum(arr, l, m);
   ll MR = maxSubArraySum(arr, m+1, h);
   ll MC = maxCrossingSum(arr, l, m, h);
   if(MC > max(ML, MR) && flag)
      return max(ML, MR);
   else return max(MC, max(ML, MR));
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--)
    {
      cin >> n;
      ll s = 0ll;
      rep(i, 0, n) cin >> a[i], s += a[i];
      flag = 0;
      cout << ((s > maxSubArraySum(a, 0, n-1))? "YES\n": "NO\n");
    }
    return 0;
}
