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
ll dp[maxn];


//dpa[k][i] means when ak = i => ak-1 <= i, bk = ak~bk-1
//dpb[k][j] means that bk = j => bk-1 >= j, ak = bk-1~bk

//a 123 <=y y >=y
//b 333 >=y >=y >= y

//a 111 <=x  <=x <=x
//b 321  >=x x <=x


//x>=y
//<=y  y y~x
//>=x  x y~x

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    T = 1;
    while(T--)
    {
      cin >> n >> m;
      dp[0] = 0ll;
      rep(i, 1, n+1) dp[i] = 1ll;
      rep(k, 0, 2*m)rep(i, 1, n+1) dp[i] = (dp[i]+dp[i-1])%MOD;
      cout << dp[n] << endl;
    }
    return 0;
}
