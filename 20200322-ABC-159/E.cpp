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
const int maxn = 2e5+7;
int n, m, k;
int a[10+5][1000+5];
int w[10+5][1000+5];
int h[10+5][1000+5];

//2^9 check H , remain to check W;

int sumQuery(int cursor, int l, int r) 
{ 
  /*int res = w[rbi][rbj];  
  res = res - w[tli-1][rbj]; 
  res = res - w[rbi][tlj-1]; 
  res = res + w[tli-1][tlj-1];
  */
  return h[r][cursor]-h[l-1][cursor]; 
} 

int getS(int S)
{
  //debug(S);
  int total = __builtin_popcount(S);
  vector<pii> allseg;
  int last = 1;
  rep(i, 0, n-1) if(S>>i&1)
  {
    allseg.pb(pii(last, i+1));
    last = i+2;
  }
  allseg.pb(pii(last, n));
  assert(allseg.size() == total+1);
  //rep(i, 0, total +1 ) cout << "LR:" << allseg[i].X << ' ' << allseg[i].Y << endl; 
  vector<int> cnt(total+1, 0);
  int cursor = 1;
  int lastc = 1;
  while(1)
  {
    if(cursor > m) break; //...bug
    bool flag = 0;
    rep(i, 0, allseg.size())
    {
      cnt[i] += sumQuery(cursor, allseg[i].X, allseg[i].Y);
      //debug(cursor); debug(cnt[i]);
      if(cnt[i] > k) {flag = 1; break;}
    }
    if(flag)
    {
      //cout << "flag "; debug(cursor);
      if(cursor == lastc) return INT_MAX;
      total++;
      lastc = cursor;
      rep(ii, 0, cnt.size()) cnt[ii] = 0;
      //cursor--;
       // from cursor carry on 
    } else {cursor++; continue;}
  }
  //debug(__builtin_popcount(0));
  //debug(total);
  return total;
}

//check T
void solve()
{
  
  cin >> n >> m >> k;
  string s;
  rep(i,1,n+1)
  {
    cin >> s;
    rep(j,1,m+1) a[i][j] = s[j-1] == '1';
    w[i][0] = 0;
    rep(j,1,m+1) w[i][j] = w[i][j-1] + a[i][j];
  }
  rep(j, 1, m+1) w[0][j] = 0;
  rep(i,1,n+1)rep(j,1,m+1) w[i][j] += w[i-1][j];
  /*rep(i,1,n+1)
  {
    rep(j,1,m+1) cout << w[i][j] << " \n"[j==m];
    cout << endl;
  }*/
  rep(j, 1, m+1) h[0][j] = 0;
  rep(j, 1, m+1) rep(i, 1, n+1) h[i][j] = h[i-1][j] + a[i][j];
  int ans = INT_MAX;
  rep(S, 0, 1<<(n-1)) //n=3 00 to 111
  {
    ans = min(ans, getS(S));
  }
  cout << ans << endl;
  return;
}


signed main()
{
  fastIO();
  T = 1;
  //cin >> T; //this
  while(T--) solve();
  return 0;
}
