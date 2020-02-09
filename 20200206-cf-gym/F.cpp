#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define debug(x) std::cout << #x << ": " << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int n, k;
const int maxn = 300+5;
const int MOD = 1e9+7;

//
bool inc[maxn];
//dp[i][j] when end with j in i th pos (X)
//dp[i][j] when end with <= j / >= j in i th pos (O)
int dp[maxn][maxn];

int dfs(int cur, int val)
{
  if(dp[cur][val] != -1) return dp[cur][val];
  if(cur == n) return 1;
  if(val < 0 || val >= n-cur) return 0;

  int ret = 0;
  if(inc[cur])
  {
    if(inc[cur+1]) ret += dfs(cur+1, val);
    else ret += dfs(cur+1, val-1);
    ret += dfs(cur, val+1);
  }else{
    if(inc[cur+1]) ret += dfs(cur+1, val);
    else ret += dfs(cur+1, val-1);
    ret += dfs(cur, val-1);
  }
  return dp[cur][val] = ret%MOD;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #define ONLINE
    #ifdef ONLINE
    freopen("monotonic.in", "r", stdin);
    freopen("monotonic.out", "w", stdout);
    #endif

    cin >> n >> k;
    int sum = 0;
    int tmp;
    memset(inc, 0, sizeof(inc));
    rep(i, 0, k)
    {
      cin >> tmp;
      sum += tmp;
      inc[sum] = 1; /// a[sum] > a[sum-1]
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, n-1) << endl;


    return 0;
}
