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
const int maxn = 3e3+7;
int n;
//ll a[maxn];
int dp[maxn][maxn];

//check T
void solve()
{
    //cin >> n; rep(i, 0, n) cin >> a[i];
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    const int mod = 998244353;
    rep(i, 1, c+1) rep(j, 1, d+1) dp[i][j] = 0;
    rep(i, 0, a+1) rep(j, 0, b+1) dp[i][j] = 1;
    //rep(i, 1, a+1) rep(j, 1, d+1) dp[i][j] = 1;
    rep(i, 1, c+1) rep(j, 1, d+1)
    {
        //cerr << dp[i][j] << " \n"[j==d];
    }
    cerr << endl;
    rep(i, 0, c+1) rep(j, 0, d+1)
    {
        //if(i > a && j > b) { dp[i][j] += mod-dp[i-1][j-1]*(i+j-2); dp[i][j] %= mod;}
        if(i >= a && j >= b){ dp[i+1][j] += dp[i][j]*(j); dp[i+1][j] %= mod; }
        if(i >= a && j >= b){ dp[i][j+1] += dp[i][j]*(i); dp[i][j+1] %= mod;}
        if(i >= a && j >= b) { dp[i+1][j+1] += mod-dp[i][j]*(i+j); dp[i+1][j+1] %= mod;}
        //dp[]
    }
    rep(i, 1, c+1)rep(j, 1, d+1)
    {
        cerr << dp[i][j] << " \n"[j==d];
    }
    cout << dp[c][d] << endl;
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
