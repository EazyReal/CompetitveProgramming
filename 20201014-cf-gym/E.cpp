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
const int maxn = 1e3+5;
int n;
//ll a[maxn];

// ith mod=k digit
int dp[maxn][maxn][11];

//check T
void solve()
{
    int m;
    string s;
    cin >> s >> m;
    int n = s.size();
    vector<int> a(n); //predetermined digit
    vector<int> p(n); //power
    p[0] = 1;
    rep(i, 0, n)
    {
        a[i] = s[i]-'0';
        if(i > 0) p[i] = p[i-1]*10%m;
    }
    //indexer smaller => val bigger
    reverse(all(p));
    // add init 
    rep(i, 0, n)rep(j, 0, m)rep(d, 0, 10) dp[i][j][d]=-1;
    //
    repinv(i, 0, n)rep(j, 0, m)
    {
        if(s[i] == '?')
        {
            //undetermined
            rep(d, 0, 10)
            {
                int val = d*p[i]%m;
                if(i != n-1)
                {
                    int pre = (j+(m-val))%m;
                    dp[i][j][d] = -1;
                    rep(d2, 0, 10) if(dp[i+1][pre][d2] != -1)
                    {
                        dp[i][j][d] = d2; break;
                    }
                }else if(i == n-1){
                    dp[i][j][d] = (val==j) ? 0 : -1; //0 is useless, onluy means not -1
                }
            }
        }else{
            // determined
            rep(d, 0, 10) dp[i][j][d] = -1;
            int &c = dp[i][j][a[i]];
            int val = a[i]*p[i]%m;
            if(i != n-1)
            {
                int pre = (j+(m-val))%m;
                c = -1;
                rep(d2, 0, 10) if(dp[i+1][pre][d2] != -1)
                {
                    c = d2; break;
                }
            }else if(i == n-1){
                c = (val==j) ? 0 : -1; //0 is useless, onluy means not -1
            }
        }
    }

    //debug
    int to_see = n-1;
    rep(d, 0, 10)
    {
        //cerr << dp[to_see][0][d] << " \n"[d==9];
    }

    vector<string> ans;
    //do not use 1 as begin
    rep(d, 1, 10)if(dp[0][0][d] != -1)
    {
        string cur;
        int dd = d;
        int mm = 0;
        rep(i, 0, n)
        {
            cur.pb(dd+'0');
            int next_mm = (mm+(m-dd*p[i]%m))%m;
            int next_dd = dp[i][mm][dd];
            mm = next_mm;
            dd = next_dd;
        }
        //reverse(all(cur));
        ans.pb(cur);
        //debug(cur);
    }
    sort(all(ans));
    if(ans.size()!=0) cout << *(ans.begin()) << endl;
    else cout << "*" << endl;

    return;
}

/*
????11? 11
1100110
*/


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
