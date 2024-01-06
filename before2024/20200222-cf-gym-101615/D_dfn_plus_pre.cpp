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
typedef pair<int, int> Edge; // color, v
vector<Edge> G[maxn];
int s[maxn], t[maxn], p[maxn], dfn; //s,t mark dfn and p is parent

void add_edge(int a, int b, int c)
{
	G[a].pb(mp(c, b));
}

void dfs(int u, int f) //mark tree structure
{
	s[u] = ++dfn;
	p[u] = f;
	for(pii& e : G[u])
	{
		int v = e.Y;
		if(v != f) dfs(v, u);
	}
	t[u] = dfn;
}

signed main()
{
  fastIO();

  cin >> n;
  int a, b, c;
	rep(i, 1, n+1) G[i].clear();
	rep(i, 0, n-1)
	{
		cin >> a >> b >> c;
		add_edge(a, b, c);
		add_edge(b, a, c);
	}
	dfn = 0;
	//rep(u, 1, n+1) sort(all(G[u]));
	dfs(1, -1); //1-indexed
	assert(dfn == n);
	vector<int> pre(n+5, 0); //prefix sum
	rep(u, 1, n+1)
	{
		sort(all(G[u]));
		int m = G[u].size();
		int i, j;
		for(i = 0; i < m; i = j)
		{
			j = i; //int j = i cause bug...
			while(j<m && G[u][j].X == G[u][i].X) j++;
			if(j == i+1) continue; //only one this color
			rep(k, i, j)
			{
				//assert(G[u][k].X == G[u][i].X);
				int v = G[u][k].Y;
				if(v == p[u]) pre[0]++, pre[s[u]]--, pre[t[u]+1]++; //s[u] = s[p[u]]+1? no in general for p may dfs other first
				else pre[s[v]]++, pre[t[v]+1]--;
			}
		}
	}
	rep(i, 1, n+1) pre[i] += pre[i-1] ;
	//rep(i, 1, n+1) cout << s[i] << ' ' << pre[i] << " \n"[i==n];
	int ans = 0;
	rep(i, 1, n+1) if(pre[s[i]] == 0) ans++;
	cout << ans << endl;
	rep(i, 1, n+1) if(pre[s[i]] == 0) cout << i << endl;

  return 0;
}
