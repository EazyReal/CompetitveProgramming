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
int n;

int fa[maxn];

struct DSU {
    vector<int> p, sz;

    DSU(int n) : p(n), sz(n,1)
    {
        iota(p.begin(), p.end(), 0);
    }

    int findset(int u)
    {
        return p[u]==u ? u : p[u] = findset(p[u]);
    }

    bool unionset(int u, int v)
    {
        u = findset(u);
        v = findset(v);
        if(u == v) return false;
        if(sz[u] < sz[v]) swap(u, v);
        p[v] = u;
        sz[u] += sz[v];
        return true;
    }
};


map<int, vector<int>> hyper_edge;

//check T
void solve()
{
    //cin >> n; rep(i, 0, n) cin >> a[i];
    cin >> n;
    int m, d;
    int cnt = n; //edge index
    rep(i, 0, n)
    {
        cin >> m;
        rep(j, 0, m)
        {
            cin >> d;
            hyper_edge[d].pb(i);
        }
    }
    DSU dsu(n);
    vector<array<int,3>> answer;
    for(auto it=hyper_edge.begin(); it!= hyper_edge.end(); ++it)
    {
        vector<int> &e = it->second;
        int nn = e.size();
        //if(nn == 1) continue;
        rep(i, 1, nn)
        {
            if (dsu.unionset(e[i], e[i-1])) answer.pb({e[i], e[i-1], it->first});
        }
    }
    int meta = dsu.findset(0);
    bool flag = 1;
    rep(i, 1, n)
    {
        if(dsu.findset(i) != meta) flag = 0;
    }
    if(flag == 0)
    {
        cout << "impossible" << endl;
        //return; 
    }else{
        for(auto ans: answer)
        {
            cout << ans[0]+1 << " " << ans[1]+1 << " " << ans[2] << endl; 
        }
    }
    
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
