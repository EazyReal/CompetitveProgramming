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
int n;
double s;

using P = pair<pii, string>;
using pdd = pair<double, double>;
vector<P> ps;

pdd operator-(pdd& a, pdd& b)
{
    return {a.X-b.X, a.Y-b.Y};
}

int to_val(pdd a)
{
    if(a.X < 0.0 && a.Y < 0.0) return 0;
    if(a.X > 0.0 && a.Y < 0.0) return 1;
    //if(a.X == 0.0 && a.Y == 0.0) return 2;
    if(a.X > 0.0 && a.Y > 0.0) return 3;
    if(a.X < 0.0 && a.Y > 0.0) return 4;
    assert(0);
}

bool cmp(P a, P b)
{
    pdd p1 = {a.X.X, a.X.Y};
    pdd p2 = {b.X.X, b.X.Y};
    pdd mid = {s/2.0, s/2.0};
    while(1)
    {
        //cout << "hi";
        p1 = p1 - mid;
        p2 = p2 - mid;
        int v1 = to_val(p1);
        int v2 = to_val(p2);
        if(v1 < v2) {return 1;}
        if(v1 > v2) {return 0;}
        mid.X /= 2.0;
        mid.Y /= 2.0;
        //cout << mid.X;
    }
}

//check T
void solve()
{
    cin >> n >> s;
    ps.clear();
    ps.resize(n);
    rep(i, 0, n)
    {
        cin >> ps[i].X.X >> ps[i].X.Y >> ps[i].Y;
    }
    sort(all(ps), cmp);
    rep(i, 0, n)
    {
        cout << ps[i].Y << endl;
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
