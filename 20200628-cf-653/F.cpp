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
const int maxn = 2e5+7;
int n, m, k;
//ll a[maxn];

//this is E2, the way to solve i geuss is consider "ab with nab" and "a+b with ab"
// to achieve k first
// then to achive m, add min ab, nab, a, bfor the over shot, - the minus better ab and extra

//check T
void solve()
{
    cin >> n >> m >>  k;
    int ti, ai, bi;
    vector<pair<int, int>> a[4];
    rep(i, 1, n+1)
    {
        cin >> ti >> ai >> bi;
        a[ai*2+bi].pb({ti,i});
    }
    rep(i, 0, 4) sort(all(a[i]));
    const int inf = 2000000;
    rep(i, 0, 4) a[i].pb({inf, inf});
    
    ll sum = 0;
    vi ans;
    bool flag = 0;
    int c[2];
    int d[4];
    
    if(flag) cout << -1 << endl;
    else cout << sum << endl;

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
