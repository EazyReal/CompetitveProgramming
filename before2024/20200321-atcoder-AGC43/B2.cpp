#include <bits/stdc++.h>
//#define LOCAL
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
const int maxn = 2e6+7;
int n;
int a[maxn];

//has 1 => can be 0 or 1
//contribution of parity to see is 0 or 1
//no 1 => can be 0 or 2, see a/2 is 0 or 1 to decide

//parity of C(n,k) can be found by lucas theorem
//my first thought is remember how much 2 factor u have with least significant bit function
//and use C(n, k) = C(n, k-1)*k/(n-k+1)

//such a beautiful problem
//learned : lucas theorem is useful, contribution thinking, stay orginized!

//bool C(int n, int k){ return (n&k) == k;} //corollary of Lucas theorem
// =>　(ni, ki), ki = 1 => ni = 1, ki = 0 => ni = 0or1 => no 2
bool C(int n, int k){ return ((n-k)^k) == n;}
// => n has all k's bit => no (0, 1) odd 

//check T
void solve()
{
	int cur = 0;
	string s;
	bool noone = 1;
	cin >> n; cin >> s; rep(i, 0, n) a[i] = s[i]-'0'-1, noone &= a[i]!=1;
	if(noone) rep(i, 0, n) a[i] >>= 1;
	int par = 0;
	rep(i, 0, n) par ^= C(n-1, i)*(a[i]&1);
	cout << par*(noone+1) << endl;
  return;
}


signed main()
{
  fastIO();
  T = 1;
  //cin >> T; //this
  while(T--) solve();
  return 0;
}


/*
15
132123321111222
*/
