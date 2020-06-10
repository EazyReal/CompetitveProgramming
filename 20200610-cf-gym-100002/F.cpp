#include <bits/stdc++.h>
#define LOCAL
using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define repinv(i, st, n) for (int i = ((n)-1); i >= (st); --i)
#define MEM(a, b) memset(a, b, sizeof(a));
#ifdef LOCAL
#define debug(x) std::cerr << #x << ": " << x << endl
#else
#define debug(x) 860111
#endif
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fileIO(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

//mt19937 mrand(random_device{}());
//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod=1e9+7;
//int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
pii operator+(const pii&x, const pii&y) { return mp(x.X+y.X, x.Y+y.Y);}
pii operator-(const pii&x, const pii&y) { return mp(x.X-y.X, x.Y-y.Y);}
//INT_MAX, ULLONG_MAX, LLONG_MAX or numeric_limits<int>::min()

inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}

//------------------------------------------------------------------------//
int T;
const int maxn = 2e2+7;
string s;
int n;
//ll a[maxn];
int dp[maxn][maxn];
int path[maxn][maxn];

int cnt(int x) //x!=0
{
  assert(x!=0);
  int ret = 0;
  while(x) x/=10, ret++;  
  return ret;
}

string build(int l, int r)
{
  string ret;
  //cout << l << " " << r << " " << path[l][r] << endl;
  if(l==r) return string(1,s[l]);
  if(path[l][r] >= 10000)
  {
    int j = path[l][r] - 10000;
    ret += build(l, j); 
    ret += build(j+1, r);
  }else{
    int d = path[l][r];
    ret += to_string((r-l+1)/d);
    ret += '(';
    ret += build(l, l+d-1);
    ret += ')';

  }
  return ret;
}

//check T
void solve()
{
  //cin >> n; rep(i, 0, n) cin >> a[i];
  cin >> s;
  n = s.size();
  rep(len, 1, n+1)rep(l, 0, n)
  {
    int r = l+len-1; // [1,r]
    if(r >= n) continue;
    dp[l][r] = len;
    rep(j, l, r)
    {
      dp[l][r] = min(dp[l][r], dp[l][j] + dp[j+1][r]);
      if(dp[l][r] == dp[l][j] + dp[j+1][r])
      {
        path[l][r] = j + 10000;
      }
    }
    for(int d = 1; d <= len; d++)if(len%d==0)
    {
      string seg = s.substr(l,d);
      bool flag = 1;
      rep(ii, 1, len/d)
      {
        if(s.substr(l+ii*d, d) != seg) {flag = 0; break;}
      }
      if(!flag) continue;
      dp[l][r] = min(dp[l][r], dp[l][l+d-1] + 2 + cnt(len/d));
      if(dp[l][r] ==  dp[l][l+d-1] + 2 + cnt(len/d))
      {
        path[l][r] = d;
      }
    }
  }
  //debug(dp[0][n-1]);
  string ans = build(0, n-1);
  cout << ans << endl;
  return;
}


//g++ -o out -std=c++11 A.cpp

signed main()
{

  //freopen("folding.in", "r", stdin);
  //freopen("folding.out", "w", stdout);
  fastIO();
  T = 1;
  //cin >> T; //this
  rep(tc, 1, T+1)
  {
    //cout << "Case #" << tc << ": ";
    solve();
  }
  return 0;
}
