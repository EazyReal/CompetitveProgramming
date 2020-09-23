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
int n, t;
//ll a[maxn];

inline bool inrange(int x, int maxv)
{
    return x >= 0 && x < maxv;
}

//check T
void solve()
{
    bool all_can = true;
    int f;
    cin >> f;
    rep(fi, 0, f)
    {
        cin >> t >> n;
        t++;
        vector<bool> dp1(t, true);
        vector<bool> dp2(t, false);
        int a, b, d;

        //cin >> a >> b; d = b-a;
        //rep(x, 0, d) dp1[x] = false;
        rep(i, 0, n)
        {
            cin >> a >> b; d = b-a;
            //cout << "dp" << i << endl;
            //rep(x, 0, t) cout << dp1[x] << " "; cout << endl;
            rep(x, 0, t) dp2[x] = false;
            rep(x, 0, t)if(dp1[x] == true)
            {
                if(inrange(x+d, t)) dp2[x+d] = true;
                if(inrange(x-d, t)) dp2[x-d] = true;
            }
            rep(x, 0, t) dp1[x] = dp2[x];
        }
        //rep(x, 0, t) cout << dp1[x] << " "; cout << endl;
        bool this_can = false;
        rep(x, 0, t) this_can |= dp1[x];
        all_can &= this_can;
    }
    cout << (all_can ? "possible" : "impossible" )<< endl;;
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
