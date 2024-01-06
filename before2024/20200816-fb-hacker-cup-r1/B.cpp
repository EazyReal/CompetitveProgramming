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
//typedef long double ld; maxwill lin for fc hacker cup 1

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
#define int ll // 1e9*5e8 ok
int T;
const int maxn = 1e6+7;
int n, k;
//ll a[maxn];
int L[maxn];
int H[maxn]; // actually h
int W[maxn];
int la, lb, lc, ld;
int wa, wb, wc, wd;
int ra, rb, rc, rd;

//check T
void solve()
{
    cin >> n >> k;
    rep(i, 0, k) cin >> L[i];
    cin >> la >> lb >> lc >> ld;
    rep(i, k, n)
    {
        L[i] = (la*L[i-2]%ld+lb*L[i-1]%ld+lc+1)%ld;
    }
    rep(i, 0, k) cin >> W[i];
    cin >> wa >> wb >> wc >> wd;
    rep(i, k, n)
    {
        W[i] = (wa*W[i-2]%wd+wb*W[i-1]%wd+wc+1)%wd;
    }
    rep(i, 0, k) cin >> H[i];
    cin >> ra >> rb >> rc >> rd;
    rep(i, k, n)
    {
        H[i] = (ra*H[i-2]%rd+rb*H[i-1]%rd+rc+1)%rd;
    }
    //start
    int sum = 0;
    int mul = 1;
    sum += (W[0]*2 + H[0]*2)%mod;
    mul = (mul*sum)%mod;
    multiset<pair<ll, ll>> segs;
    segs.insert({L[0], L[0]+W[0]});
    // calc first ed
    rep(i, 1, n)
    {
        mul *= sum;
        mul %= mod;
    }
    cout << mul << endl;

    return;
}


//g++ -o out -std=c++11 A.cpp

signed main()
{
    fastIO();
    fileIO("perimetric_chapter_1_input.txt", "perimetric_chapter_1_output.txt");
    T = 1;
    cin >> T; //this
    rep(tc, 1, T+1)
    {
        cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}
