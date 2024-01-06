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
#define int ll
int T;
const int maxn = 2e5+7;
string C, J;
string ANS;
int n, m;
//ll a[maxn];

int pow(int a,int b) {int res=1; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}

//edit distance
int dis(string A, string B)
{
  int n = A.size();
  int m = B.size();
  vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); 
  rep(i, 0, n+1)rep(j, 0, m+1)
  {
    if(i == 0) dp[i][j] = j;
    else if(j == 0) dp[i][j] = i;
    else if(A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1];
    else {
      dp[i][j] = 1 + min({
        dp[i][j - 1],
        dp[i-1][j],
        dp[i-1][j - 1]
      });
    }
  }
  return dp[n][m];
}
const int ALPHA = 26;

//check T
void solve()
{
  cin >> C;
  cin >> J;
  n = C.size();
  m = J.size();
  int mins = 1000, mind = 1000;
  rep(len, 1, 5)
  {
    rep(gen, 0, pow(ALPHA, len))
    {
      string TMP(len,'A');
      rep(i, 0, len)
      {
        TMP[i] += gen/(pow(ALPHA,i))%ALPHA;
        //debug(TMP);
      }
      int dC = dis(C,TMP);
      int dJ = dis(J,TMP);
      if(dC+dJ < mins || (dC+dJ==mins && abs(dC-dJ) < mind))
      {
        mins = dC+dJ;
        mind = abs(dC-dJ);
        ANS = TMP;
      }

    }
  }
  cout << ANS << endl;
  return;
}


//g++ -o out -std=c++11 A.cpp

signed main()
{
  fastIO();
  T = 1;
  cin >> T; //this
  rep(tc, 1, T+1)
  {
    cout << "Case #" << tc << ": ";
    solve();
  }
  return 0;
}
