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

inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}

//------------------------------------------------------------------------//
int T;
const int maxn = 5e4+7;
int n;
//vector<int> es;
vector<pair<pii, bool>> G[maxn];
bool tag[maxn];

void add_edge(int a, int b, int c)
{
  G[a].pb(mp(mp(c, b), 0)); //.Y = vis, .X = (color, to)
  G[b].pb(mp(mp(c, a), 0));
}

//(directed so wont be blocked in another direction)
void dfs_dup(int u, int p)//mark dup, block by p and edge, only mark once O(n)
{
	tag[u] = 1;
	for(auto&e:G[u]) if(e.X.Y != p && !e.Y)
	{
		e.Y = 1;
		dfs_dup(e.X.Y, u);
	}
}

void dfs_all(int u, int p) //O(n) on all dfs_all and O(n) on all dfs_dup
{
	rep(i, 1, G[u].size())if(G[u][i].X.X == G[u][i-1].X.X) //regardless of is p or not, for dup edge, mark all taged
	{
		int v =  G[u][i].X.Y;
		if(!G[u][i].Y) {G[u][i].Y = 1; dfs_dup(v, u);}
		v = G[u][i-1].X.Y;
		if(!G[u][i-1].Y) {G[u][i-1].Y = 1; dfs_dup(v, u);}
	}
	for(auto&e:G[u]) if(e.X.Y != p) dfs_all(e.X.Y, u); //for all point do so
}

signed main()
{
  fastIO();

  cin >> n;
  int a, b, c;
  rep(i, 0, n-1)
  {
    cin >> a >> b >> c;
    add_edge(a, b, c);
  }
	rep(i, 1, n+1) sort(all(G[i]));
	memset(tag, 0, sizeof(tag));
	dfs_all(1, -1);
	int ans = 0;
	rep(i, 1, n+1)if(!tag[i]) ans++;
	cout << ans << endl;
	rep(i, 1, n+1)if(!tag[i]) cout << i << endl;

  return 0;
}
