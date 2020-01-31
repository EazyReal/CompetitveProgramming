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

int T;
int n, m;
const int maxn = 1001+5;
const int maxm = 10+5;
const int MOD = 1e9+7;
int a[10+5], b[10+5];
ll dp[maxm][maxn][maxn];
ll s[maxm][maxn][maxn];

//step1
//dp[k][i][j] means when ak = i, bj = j, the method count , note that ak <= bk, i>j => = 0
//dp[k][i][j] = sigma j to i (dp)
//step2
//dp[k][i] means when ak = i => ak-1 <= i, bk = i~bk-1

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    T = 1;
    while(T--)
    {
      cin >> n >> m;
      rep(k, 0, m)rep(i, 0, n+1)rep(j, 0, n+1) dp[k][i][j] = 0, s[k][i][j] = 0;
      rep(i, 1, n+1)rep(j, i, n+1) dp[0][i][j] = 1, s[0][i][j]=s[0][i][j-1]+dp[0][i][j], s[0][i][j]%=MOD;
      rep(k, 1, m)
      {
        rep(i, 1, n+1)rep(j, i, n+1)
        {
          rep(ii, i, n+1) dp[k][i][j] += s[k-1][ii][j]-s[k-1][ii][i-1], dp[k][i][j]%=MOD;
          s[k][i][j] = s[k][i][j-1]+dp[k][i][j], s[k][i][j]%=MOD;
        }
      }
    }
    ll ret = 0ll;
    rep(i, 1, n+1) ret += dp[m-1][i][n] ,ret%= MOD;
    cout << ret << endl;
    return 0;
}
