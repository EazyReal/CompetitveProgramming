#include <bits/stdc++.h>
#define LOCAL
using namespace std;

#define int ll

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
int n;
vector<pii> hs;
vector<pii> ds;


bool isp(pii a, pii b) //assume no 0,0, check parrel
{
  bool flag1 = 0, flag2 = 0;
 // if(a.X == 0 && b.X == 0) return 1;
  //if(a.Y == 0 && b.Y == 0) return 1;
  if(a.X*b.Y == a.Y*b.X ) return 1;
  //else if(a.X*b.Y == -a.Y*b.X ) return 1;
  else return 0;
}

void dfs(vector<vi>& G, vector<int>& vis, int u, int cc)
{
  vis[u] = cc;
  rep(i, 0, n) if(G[u][i] && vis[i]==-1) 
  {
    dfs(G, vis, i, cc);
  }
}

int solve2(pii d)
{
  vector<vi> G(n, vi(n,0));
  rep(i, 0, n)rep(j, 0, n)
  {
    if(i != j && isp(hs[j]-hs[i], d)) G[i][j] = G[j][i] = 1;
    //cout << G[i][j] << " ";
    //if(j == n-1) cout << endl;
  }
  vector<int> vis(n, -1);
  int cc = 0;
  rep(i, 0, n)
  {
    if(vis[i] == -1)
    {
      dfs(G, vis, i, cc);
      cc++;
    }
  }
  vector<int> ccs(cc+1, 0);
  rep(i, 0, n) ccs[vis[i]]++;
  int ret = 0;
  rep(i, 0, cc) if(ccs[i] >= 2) ret += ccs[i];
  if(ret%2 == 1) return min(ret+1, n);
  else return min(ret+2, n);
}

//check T
void solve()
{
  cin >> n; 
  hs.resize(n);
  rep(i, 0, n) cin >> hs[i].X >> hs[i].Y;
  sort(all(hs));
  ds.clear();
  rep(i, 0, n)rep(j, i+1, n)
  {
    ds.pb(hs[j]-hs[i]); //one possibility
  }
  int ans = 1;
  for(auto &d: ds)
  {
    //debug(d.X); debug(d.Y);
    //debug(solve2(d));
    ans = max(ans, solve2(d));
  }
  cout << ans << endl;
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
