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
int n, k, w;
//ll a[maxn];
int L[maxn];
int R[maxn]; // actually h
int la, lb, lc, ld;
int ra, rb, rc, rd;

//check T
void solve()
{
    cin >> n >> k >> w;
    rep(i, 0, k) cin >> L[i];
    cin >> la >> lb >> lc >> ld;
    rep(i, k, n)
    {
        L[i] = (la*L[i-2]%ld+lb*L[i-1]%ld+lc+1)%ld;
    }
    rep(i, 0, k) cin >> R[i];
    cin >> ra >> rb >> rc >> rd;
    rep(i, k, n)
    {
        R[i] = (ra*R[i-2]%rd+rb*R[i-1]%rd+rc+1)%rd;
    }
    int sum = 0;
    int mul = 1;
    int last = -1;
    queue<pair<ll, ll>> q;
    multiset<ll> hs;
    rep(i, 0, n)
    {
        /*
        |  | |  |
        ------
         */
        while(!q.empty() && q.front().first < L[i]) //< not <=
        {
            auto pos = hs.find(q.front().second);
            hs.erase(pos);
            q.pop();
        }
        if(L[i] > last)
        {
            sum += w*2 + R[i]*2;
            sum %= mod;
        }else{
            //when i = 0, will not enter here
            //wont have enclosed (w is the same)
            //debug(*hs.rbegin());
            if(!hs.empty()) sum += max(0ll, R[i]-*hs.rbegin())*2;
            else sum += R[i]*2;
            sum += (L[i]-L[i-1])*2; //w is same
            sum %= mod;
        }
        mul *= sum;
        mul %= mod;
        last = L[i]+w;
        q.push({L[i]+w, R[i]});
        hs.insert(R[i]);
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
