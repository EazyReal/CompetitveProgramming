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
#define fastIO() ios_base::sync_with_stdio(false)//; //cin.tie(0)//; cout.tie(0)
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
int n, k;
vi S[maxn];
//int maxv;

int q(int l, int r)
{
    if(l == r) return 0;
    vector<int> ids;
    rep(i, l, r)
    {
    for(auto& idx : S[i]) ids.pb(idx);
    }
    cout << "? " << ids.size(); 
    for(auto& idx : ids) cout << " " << idx;
    cout << endl;
    int ret;
    cin >> ret;
    return ret;
}


int q2(int last)
{
    vector<int> ids;
    set<int> s;
    for(auto& idx : S[last]) s.insert(idx);
    rep(i, 1, n+1) if(s.find(i) == s.end()) ids.pb(i);
    cout << "? " << ids.size(); 
    for(auto& idx : ids) cout << " " << idx;
    cout << endl;
    int ret;
    cin >> ret;
    return ret;
}

void guess(int id, int v1, int v2)
{
    string AC;
    cout << "!";
    rep(i, 0, k) cout << " " << (i==id ? v2 : v1);
    cout << endl;
    cin >> AC;
} 
//check T
void solve()
{
    //input info
    cin >> n >> k;
    int ci, tmp;
    rep(i, 0, k)
    {
        S[i].clear();
        cin >> ci;
        rep(j, 0, ci)
        {
            cin >> tmp;
            S[i].pb(tmp);
        }
    }
    //if(k == 1) return ;
    // binary search for maxv location
    int l = 0, r = k, m;
    int maxv = q(l,r);
    while(l+1 < r)
    {
        m = (l+r)/2;
        int v1 = q(l, m);
        if(v1 == maxv) r = m; 
        else l = m; 
    }
    int max2v = q2(l);
    guess(l, maxv, max2v);

    return;
}


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

/*
1
8
4
2              
1 2
2 
3 4
2 
5 6
2 
7 8



1 
9 4
3 1 3 5
2 2 4
2 6 9
2 7 8

1 
9 3
3 1 3 5
2 2 4
4 6 9 7 8
*/