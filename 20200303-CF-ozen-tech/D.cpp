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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

//mt19937 mrand(random_device{}());
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
const int maxn = 1e3+7;
const int maxb = 11;
int n;
int G2[maxn][maxn];
vi G[maxn];

namespace lca{
  int p[maxb][maxn];
	int dep[maxn];
  void dfs(int u, int f)
  {
    p[0][u] = f;
    dep[u] = dep[f] + 1;
    for(auto v : G[u]) if(v != f) dfs(v, u);
  }

  int lca(int a, int b)
  {
    if(dep[a] < dep[b]) swap(a, b);
    //assert(dep[a] >= dep[b]);
    repinv(i, 0, maxb) if(dep[p[i][a]] >= dep[b]) a = p[i][a]; //< -> >=...
    if(a == b) return a;
    repinv(i, 0, maxb)
    {
      if(p[i][a] != p[i][b]) a = p[i][a], b = p[i][b];
    }
    return p[0][a];
  }

  void build(int n)
  {
    dep[0] = -1;
    dfs(1, 0);
    p[0][1] = 1;
    rep(i, 1, maxb) rep(u, 1, n+1) p[i][u] = p[i-1][p[i-1][u]];
  }

  int dist(int a, int b)
  {
    return dep[a] + dep[b] - 2*dep[lca(a, b)];
  }
}

int dd[maxn][maxn];
bool mark[maxn];

bool go(int u, int v, int w, int p)
{
	if(u == v) {if(u!=w){mark[u] = 1;} return 1;} //destination
	bool ret = 0;
	for(int x:G[u])if(x!=p)
	{
		//if(mark[x]==1) continue;
		ret &= go(x, v, w, u); //path
	}
	if(ret && u!=w) mark[u] = 1;
	return ret;
}

void solve()
{
	cin >> n;
	int a, b;
	rep(i, 0, n-1)
	{
		cin >> a >> b;
		G2[a][b] = G2[b][a] = 1;
		G[a].pb(b);
		G[b].pb(a);
	}
	lca::build(n);

	priority_queue<pair<int, pii>> pq;
	rep(i, 1, n)rep(j, 1, i)
	{
		dd[i][j] = dd[j][i] = lca::dist(i,j);
		pq.push(mp(dd[i][j],mp(i,j)));
	}
	memset(mark, 0, sizeof(mark));
	//priority_queue<pair<int, pii>> pq; //dist
	while(!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		int u = cur.Y.X, v = cur.Y.Y;
		while(!pq.empty() && (mark[u] && mark[v])) { cur = pq.top(); pq.pop();} //?
		if(pq.empty()) break;
		//cur = maxdis without mark
		cout << "? " << u << " " << v << endl;
		int w;
		cin >> w;
		//if(w == u || w == v) {cout << "! " << w << endl; return;}
		go(u, v, w, -1);
		//debug(pq.size());
	}
	rep(i, 1, n+1) if(!mark[i])  {cout << "! " << i << endl; return;}

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
/*
stuck:
	* do observations and see properties
	* binary search? DP? DS? flow?
	* be organized

before upload:
	* int overflow, array bounds
	* special cases (min, max, special)
*/
