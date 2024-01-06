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
int n;
//ll a[maxn];

int U;
//check T
void solve()
{
  //cin >> n; rep(i, 0, n) cin >> a[i];
  n = 10000;
  cin >> U;
  vector<int> Q(10000);
  vector<string> R(10000);
  rep(i, 0, 10000)
  {
    cin >> Q[i] >> R[i];
  }
  set<char> dic;
  rep(i, 0, n)
  {
    for(char &c : R[i]) {dic.insert(c);}
  }
  map<char, int> stat;
  map<char, int> stat0;
  for(auto c : dic) stat[c] = 0;
  for(auto c : dic) stat0[c] = 0;
  vector<char> ans(10);
  rep(i, 0, n)
  {
    int sz = R[i].size();
    for(char &c : R[i]) {stat[c]++;}
    stat0[R[i][0]]++;
  }

  //0 is not present in  1 size
  vector<pair<int,char>> conv0;
  for(auto it = stat0.begin(); it != stat0.end(); it++)
  {
    //debug(it->first);
    //debug(it->second);
    conv0.pb(mp(it->Y, it->X));
  }
  sort(all(conv0));
  ans[0] = conv0[0].Y;
  debug(ans[0]);

  //conv other
  vector<pair<int,char>> conv;
  for(auto it = stat0.begin(); it != stat0.end(); it++)
  {
    debug(it->first);
    debug(it->second);
    if(it->X != ans[0]) conv.pb(mp(it->Y, it->X));
  }
  sort(all(conv));
  //except 0 
  rep(i, 1, 10) ans[i] = conv[9-i].Y;

  rep(i, 0, 10) cout << ans[i];
  cout << endl;

  return;
}


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
