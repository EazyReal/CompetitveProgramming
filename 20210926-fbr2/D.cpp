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
int n, m;

//check T
void solve()
{
    cin >> n >> m;
    //vector<vector<int>> a(n+1, vector<int>(m, 0));
    map<int, int> thro;
    map<int, int> cnt[2];
    int k = 0;
    int s = 0;
    int x;
    rep(i, 0, n+1)
    {
        k ^= 1;
        cnt[k].clear();
        rep(j, 0, m)
        {
            cin >> x;
            cnt[k][x]++;
            if(i == 0) thro[x]++;
        }
        if(i == 0) continue;

        int coda = 0;

        if(i != n)
        {
            for(pii p: thro)
            {
                thro[p.X] = min(p.Y, cnt[k][p.X]); //p.Y is bug
            }
        }else{ // last round 
            coda = 0;
            for(pii p: thro)
            {
                if(p.Y > 0) { 
                    coda += p.Y;
                    //cerr << "remain " << p.X << " " << p.Y << endl;
                    cnt[k^1][p.X] = max(0, cnt[k^1][p.X] - p.Y);
                }
            }
            //cerr << "coda : " << coda << endl;
        }

        for(pii p: cnt[k]) //k = new
        {
            int price =  max(0, p.Y - cnt[k^1][p.X]); // use same
            if(price > 0 && i == n)
            {
                int use =  min(coda, price);
                coda -= use;
                price -= use;
            }
            cerr << "price by : " << p.X << " " << price << endl;
            s += price;
        }
    }
    cout << s << endl;

    return;
}


//g++ -o out -std=c++11 A.cpp

signed main()
{
    //fileIO(".txt", "_out.txt");
    //fileIO(".txt", "_out.txt");
    fastIO();
    T = 1;
    cin >> T; //this
    rep(tc, 1, T+1)
    {
        cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}
