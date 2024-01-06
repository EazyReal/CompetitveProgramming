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
const int maxn = 500+7;
int n, m;
int f[maxn][maxn];
//int dp[maxn][maxn]; //use f enough
int p[maxn];
int u[maxn], v[maxn], t1[maxn], t2[maxn]; // from, to, start time

/////////

bool G[maxn][maxn]; //bipartite
bool vis[maxn];
int match[maxn];

bool dfs(int x)
{
    rep(y, 0, m) if(G[x][y] && !vis[y])
    {
        vis[y] = 1;
        if(match[y] == -1 || dfs(match[y]))
        {
            match[y] = x;
            return true;
        }
    }
    return false;
}

int maxBPM() 
{ 
    memset(match, -1, sizeof(match)); 
    int result = 0;  
    rep(x, 0, m)
    {
        memset(vis, 0, sizeof(vis)); 
        if(dfs(x)) result++; 
    } 
    return result; 
} 

/////////


//check T
void solve()
{
    //cin >> n; rep(i, 0, n) cin >> a[i];
    cin >> n >> m;
    rep(i, 0, n) cin >> p[i];
    rep(i, 0, n) rep(j, 0, n)
    {
        cin >> f[i][j];
        f[i][j] += p[j];
    }
    //rep(i, 0, n) rep(j, 0, n) cerr << f[i][j] << " \n"[j==n-1]; 
    //flights
    rep(i, 0, m)
    {
        cin >> u[i] >> v[i] >> t1[i]; //departure time
        u[i]--; v[i]--;
        t2[i] = t1[i] + f[u[i]][v[i]]; //end time (that can take off)
    }
    //flyod //enumerate middle j
    // f[i][j] = from i(can depart) to j, min time to arrive and can depart
    rep(j, 0, n)rep(i, 0, n)rep(k, 0, n)
    {
        f[i][k] = min(f[i][k], f[i][j] + f[j][k]);
    }
    //build dependency (if G[a][b] == 1 means a flight can to b flight)
    rep(i, 0, m) memset(G[i], 0, sizeof(G[i]));
    // if i can go to j 
    rep(i, 0, m)rep(j, 0, m) if(i!=j)
    {
        int time_to;
        if(v[i] == u[j]) time_to = 0; //no double count waiting when no itermidiate flight 
        else time_to = f[v[i]][u[j]];
        if(t2[i] + time_to <= t1[j])
        {
            G[i][j] = 1;
        }
    }
    //rep(i, 0, n) rep(j, 0, n) cerr << f[i][j] << " \n"[j==n-1]; 
    //rep(i, 0, m) rep(j, 0, m) cerr << G[i][j] << " \n"[j==m-1]; 
    //cerr << maxBPM() << endl;
    cout << m - maxBPM() << endl;

    return;
}


//g++ -o out -std=c++11 A.cpp

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
