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
const int maxn = 2e3+7;
int n, k;
//ll a[maxn];

string ds[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string s[maxn];
int dp[maxn][maxn];
int path[maxn];

int diff(string &a, string &b) //a origin, b target
{
  rep(i, 0, 7) if(a[i] == '1' && b[i] == '0') return -1;
  int cnt = 0;
  rep(i, 0, 7) if(a[i] == '0' && b[i] == '1') cnt++;
  return cnt;
}

bool dfs(int id, int r) //id and remainning
{
  int& ret = dp[id][r];
  if(ret != -1) return ret;
  if(id >= n && r > 0) return false;
  if(id == n && r == 0) return true;
  ret = 0;
  repinv(i, 0, 10) //try 9 to 0
  {
    int cc = diff(s[id], ds[i]);
    //debug(cc); ok
    if(cc == -1 || cc > r) continue; //cannot do
    if(dfs(id+1, r-cc)) {path[id] = i; return 1;}
  }
  return 0;
}

//check T
void solve()
{
  cin >> n >> k;
  rep(i, 0, n) cin >> s[i];
  rep(i, 0, n+1) rep(di, 0, k+1) dp[i][di] = -1;
  bool alliswell = dfs(0, k);
  if(!alliswell) {cout << -1 << endl; return;}
  rep(i, 0, n) cout << path[i];
  cout << endl;
  return;
}


signed main()
{
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
