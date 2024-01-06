#include <bits/stdc++.h>
//#define LOCAL
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
const int maxn = 2e3+7;
int n;
int a[maxn];
vector<int> G[maxn];
vector<int> G2[maxn];
int c[maxn];
int usedc[maxn][15];

void dfs(int u, int cc)
{
  c[u] = cc;
  for(int v:G[u])
  {
    if(c[v] == -1)
    {
      dfs(v, cc);
    }
  }

}

bool cmp(int i, int j)
{
  return G2[i].size()<G2[j].size();
}

//check T
void solve()
{
	cin >> n;
  rep(i, 0, n) cin >> a[i], c[i] = -1;//c vvis
  rep(i, 0, n) {G[i].clear(); G2[i].clear();}
  rep(i, 0, n)rep(j, 1, 12) usedc[i][j] = 0;
  rep(i, 0, n)rep(j, 0, n)
  {
    if(gcd(a[i],a[j]) != 1)
    {
      G[i].pb(j);
      G[j].pb(i);
    }else{
      G2[i].pb(j);
      G2[j].pb(i);
    }
  }
  vi p(n);
  rep(i, 0, n) p[i] = i;
  sort(all(p), cmp);
  //vi pp(n);
  //rep(i, 0, n) pp[i] = p[i];
  repinv(i, 0, n)
  {
    int u = p[i];
    if(c[u] == -1)
    {
      int ch = -1;
      rep(ci, 1, 12) if(!usedc[u][ci]) {c[u] = ci, ch = ci; break;}
      for(int v : G2[u]) usedc[v][ch] = 1;
      //assert(ch != -1);
    }
  }
  int cc = 1;
  rep(i, 0, n) cc = max(cc, c[i]);

  /*int cc = 0;
  rep(i, 0, n) if(c[i]==-1) dfs(i, ++cc);*/
  assert(cc <= 11);
  cout << cc << endl;
  rep(i, 0, n) cout << c[i] << " \n"[i==n-1];
  return;
}

// 1 3 6 3 2 


signed main()
{
  fastIO();
  T = 1;
  cin >> T; //this
  while(T--) solve();
  return 0;
}
