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
const int maxn = 8e5+7;
int n;
int a, b;
vector<int> G[maxn];
int f[maxn];
int sz[maxn]; // size of subtree including itself
int sd[maxn]; // summation of depth
int son[maxn]; // bigger sub
int dp[maxn];
set<int> has; //if prev has freq
map<int, int> fsd; // freq summation of depth
map<int, int> fsz; // freq summation of depth
int cnt;

// find heavy son
int dfs1(int u, int p)
{
    sz[u] = 1;
    sd[u] = 0;
    son[u] = G[u][0];
    for(int v: G[u]) if(v != p)
    {
        dfs1(v, u);
        sz[u] += sz[v];
        sd[u] += sd[v] + sz[v]; // summation of depth
        if(sz[v] > sz[son[u]]) son[u] = v;
    }
}


void calc(int u, int p, int sv)
{
    fsz[f[u]]  = 1;
    fsd[f[u]]  = 0;
    for(int v: G[u]) if(v != p)
    {
        calc(v, u, sv);
    }
}

void reset()
{
    fsz.clear();
    fsd.clear();
}

int dfs2(int u, int p, bool sv)
{
    //fsz[f[u]]++;
    //fsd[f[u]] = 0;

    //dfs light
    for(int v: G[u]) if(v != p && v != son[u])
    {
        dfs2(v, u, 0);
    }
    //dfs heavy exists
    if(G[u].size() >= 3) dfs2(son[u], u, 1);
    //dfs light 2
    for(int v: G[u]) if(v != p && v != son[u])
    {
        calc(v, u, 1);
    }
    // update?
    if(!sv) reset();
}

//check T
void solve()
{
    cin >> n;
    rep(i, 0, n) G[i].clear();
    fsz.clear();
    fsd.clear();
    cnt = 0;
    rep(i, 0, n-1)
    {
        cin >> a >> b;
        G[--a].pb(--b);
        G[b].pb(a);
    }
    rep(i, 0, n) cin >> f[i];
    dfs1(0, -1);
    dfs2(0, -1, 1);
    cout << sd-cnt << endl;
    return;
}


//g++ -o out -std=c++11 A.cpp

signed main()
{
    //fileIO(".txt", "_out.txt");
    //fileIO(".txt", "_out.txt");
    fastIO();
    T = 1;
    cin >> T; //this
    rep(tc, 1, T+1)
    {
        //cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}
