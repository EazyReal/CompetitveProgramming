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
const int maxn = 2e3+7;
int n;
//ll a[maxn];
int w[maxn];
int d[maxn];
vi ans[maxn];
vi again[maxn*3];

//check T
void solve()
{
    int m, n, ww, h;
    cin >> m >> n >> ww >> h;
    set<pii> s;
    rep(i, 0, m) {cin >> w[i]; w[i]/=ww; s.insert({w[i], i});}
    rep(i, 0, n) cin >> d[i];
    // day
    bool flag = 0;
    rep(t, 0, n)
    {
        for(auto id : again[t])
        {
            s.insert({w[id], id});
        }
        while(d[t] > 0)
        {
            if(s.size() == 0 )
            {
                flag = 1;
                break;
            }
            pii bst = *(s.rbegin()); //can be empty?
            s.erase(bst);
            int id = bst.Y;
            w[id]--;
            ans[id].pb(t+1);
            rep(i, 0, ww) d[t+i]--;
            again[t+ww+h].pb(id);
            //debug(t);
        }
    }
    //check if any  doest not fit constraint of d or w
    bool ok = 1;
    rep(i, 0, n) ok &= d[i] == 0;
    rep(i, 0, m) ok &= w[i] == 0;
    //output 
    if((!ok) || flag) cout << -1 << endl;
    else{
        cout << 1 << endl;
        rep(i, 0, m)
        {
            for(auto xx: ans[i]) cout << xx << " \n"[xx==*(ans[i].rbegin())];
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
    //cin >> T; //this
    rep(tc, 1, T+1)
    {
        //cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}
