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
const ll mod=1000000007;
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
int n;
string s;

//check T
void solve()
{
    cin >> n >> s;
    int h = 0; //hand 
    int a = 0; //answer
    int pO = -1;
    int pX = -1;
    int sum = 0; //prev sum

    rep(i, 0, n) if(s[i] != 'F')
    {
        h = (s[i]=='O');
        break;
    }

    rep(i, 0, n)
    {
        // record last diff
        if(s[i] == 'X') pX = i;
        if(s[i] == 'O') pO = i;
        // update
        if(s[i] == 'X' && h == 0)
        {
            h^=1;
            sum += pO+1;
            sum %= mod;
        }
        else if(s[i] == 'O' && h == 1)
        {
            h^=1;
            sum += pX+1;
            sum %= mod;
        }
        a += sum;
        a %= mod;
    }
    cout << a << endl;
    return;
}


//g++ -o out -std=c++11 A.cpp

signed main()
{
    //fileIO("weak_typing_chapter_2_validation_input.txt", "weak_typing_chapter_2_validation_output.txt");
    //fileIO("weak_typing_chapter_2_input.txt", "weak_typing_chapter_2_output.txt");
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
