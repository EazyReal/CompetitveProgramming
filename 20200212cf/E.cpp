#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define repinv(i, st, n) for (int i = ((n)-1); i >= (st); --i)
#define MEM(a, b) memset(a, b, sizeof(a));

#define debug(x) std::cout << #x << ": " << x << endl
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fileIO(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

mt19937 mrand(random_device{}());
const ll mod=1e9+7;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//INT_MAX, ULLONG_MAX, LLONG_MAX or numeric_limits<int>::min()

//------------------------------------------------------------------------//

//after contest
//70946355	Feb/13/2020 17:51UTC+8	maxwill	E - Erase Subsequences	GNU C++17	Accepted	93 ms	600 KB

int T;
string s, t;
int n, m;
const int maxn = 400+5;
int dp[maxn][maxn];

signed main()
{
  fastIO();
  cin >> T;
  while(T--)
  {
    cin >> s >> t;
    n = s.size();
    m = t.size();
    bool ok = 0;
    rep(l, 1, m+1) // l = 1st part's len
    {
      int r = m-l; // r = 2nd part's len
      rep(i, 0, n+1) MEM(dp[i], -1); // set 0 to n not 1 to n
      rep(i, 0, n+1) dp[i][0] = 0; //base case, no first used ;
      rep(i, 0, n)
      {
        rep(j, 0, min(l+1, i+1)) //j<=i //bug:care l should be included cause use as scend part is judged with-1
        {
          dp[i+1][j] = max(dp[i+1][j], dp[i][j]); //passing value, bug:j->j+1(not passing unused)
          if(s[i] == t[j]) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]); //use i as first part
          if(dp[i][j] >= 0 && dp[i][j] < r && s[i] == t[l+dp[i][j]]) dp[i+1][j] = max(dp[i+1][j], dp[i][j]+1); //use i as second part
        }
      }
      /*
      debug(r);
      debug(dp[n][l]);
      rep(j, 0, l+1){
        //debug(j);
        rep(i, 0, n+1) cout << dp[i][j] << ' ';
        cout << endl;
      }
      */
      if(dp[n][l] == r){
        ok = 1;
        cout << "YES" << endl;
        break;
      }
    }
    if(!ok) cout << "NO" << endl;
  }
  return 0;
}
