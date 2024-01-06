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
int n;
//ll a[maxn];

vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b)
{
    int d = a.size();
    vector<vector<int>> ret = vector<vector<int> >(d, vector<int>(d,0ll));
    rep(i, 0, d) rep(j, 0, d) rep(k, 0, d)
    {
        ret[i][j] += a[i][k] * b[k][j];
        ret[i][j] %= mod;
    }
    return ret;
}

vector<vector<int>> pow(vector<vector<int>> a, ll p)
{
    int d = a.size();
    vector<vector<int>> ret = vector<vector<int> >(d, vector<int>(d,0ll));
    rep(i, 0, d) rep(j, 0, d) if(i==j) ret[i][j] = 1ll; //I
    for(;p;p>>=1)
    {
        if(p&1ll) ret = mul(a, ret);
        a = mul(a, a);
        //rep(i, 0, d) rep(j, 0, d) cerr << a[i][j] << " \n"[j==d-1];
    }
    return ret;
}


//check T
void solve()
{
    //cin >> n; rep(i, 0, n) cin >> a[i];
    cin >> n;
    int d = 3;
    vector<vector<int>> T = vector<vector<int> >(d, vector<int>(d,0ll)); 
    //T[0][0] = 0;
    T[0][1] = 1;
    T[1][0] = 2;
    T[1][1] = 1;
    T[2][2] = 1;
    vector<vector<int>> T3(T);
    T3[1][2] = 1;
    vector<vector<int>> T21;
    T21 = mul(T3, mul(T, T));
    //rep(i, 0, d) rep(j, 0, d) cerr << T[i][j] << " \n"[j==d-1];
    //rep(i, 0, d) rep(j, 0, d) cerr << T3[i][j] << " \n"[j==d-1];
    //rep(i, 0, d) rep(j, 0, d) cerr << T21[i][j] << " \n"[j==d-1];
    //if(n <= 4)
    vector<vector<int>> TT = vector<vector<int> >(d, vector<int>(d,0ll)); 

    if(n/3 > 0)
    {
        TT = pow(T21, n/3);
    }else{
        rep(i, 0, d)rep(j, 0, d) if(i==j) T[i][j] = 1;
    }
    rep(i, 0, n%3) TT = mul(T, TT);
    //rep(i, 0, d) rep(j, 0, d) cerr << TT[i][j] << " \n"[j==d-1];

    cout << TT[1][2]*4%mod << endl;

    return;
}


//g++ -o out -std=c++11 A.cpp

signed main()
{
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
