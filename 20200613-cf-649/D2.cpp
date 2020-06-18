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
vi G[maxn];
bool vis[maxn];
int dep[maxn];
vi stk;
bool big_cycle;
vi save_loop;
int t;

void dfs(int u, int p, int d)
{
    vis[u] = 1;
    dep[u] = d;
    stk.pb(u);
    for(int v:G[u]) if(v != p)
    {
        if(!vis[v]) dfs(v, u, d+1);
        else if(v!=p){
            int m = stk.size();
            //assert(m == dep[u] - dep[v] + 1);
            int sz = dep[u] - dep[v] + 1;
            if(sz <= 0) continue;
            //debug(u);
            //debug(dep[u]);
            //debug(v);
            //debug(dep[v]);
            //debug(sz);
            if(sz <= k) //case 2
            {
                cout << 2 << endl;
                cout << sz << endl;
                rep(i, m-sz, m) cout << stk[i] << " \n"[i==m-1];
                exit(0);
            }else{
                if(big_cycle == 1) continue;
                else{
                    big_cycle = 1;
                    rep(i, m-sz, m) save_loop.pb(stk[i]);
                }
            }
        }
    }
    stk.pop_back();
}


//check T
void solve()
{
    cin >> n >> m >> k;
    int a, b;
    //rep()
    rep(i, 0, m)
    {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    memset(vis, 0, sizeof(vis));
    memset(dep, 0, sizeof(dep));
    //vis[1] = 1;
    t = 0;
    big_cycle = 0;
    dfs(1, -1, 1);
    //if big simple cycle
    if(big_cycle)
    {
        cout << 1 << endl;
        rep(i, 0, (k+1)/2)
        {
            cout << save_loop[i*2] << " \n"[i==(k+1)/2-1];
        }
        return;
    }
    //if no any cycle
    cout << 1 << endl;
    int d1 = 0, d0 = 0;
    rep(i, 1, n+1)
    {
        if(dep[i]%2 == 1) d1++;
        else d0++;
    }
    int cnt = 0;
    if(d1 > d0)
    {
        rep(i, 1, n+1)if(dep[i]%2 == 1)
        {
            cnt++;
            cout << i << " \n"[cnt == (k+1)/2];
            if(cnt == (k+1)/2) break;
        }
    }else{
        rep(i, 1, n+1)if(dep[i]%2 == 0)
        {
            cnt++;
            cout << i << " \n"[cnt == (k+1)/2];
            if(cnt == (k+1)/2) break;
        }
    }

    return;
}


//g++ -o out -std=c++11 A.cpp

signed main()
{
    fastIO();
    T = 1;
    /// cin >> T; //this
    rep(tc, 1, T+1)
    {
        //cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}

/*
6 6 3
1 2 2 3 3 4 4 5 5 6 6 1


7 7 6
1 2 2 3 3 4 4 5 5 6 6 7 7 2

7 7 5
1 2 2 3 3 4 4 5 5 6 6 7 7 2
*/