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
int n;
//ll a[maxn];

//check T
const int maxb = 30;

void solve()
{
	cin >> n;
  if(n <= 30)
  {
    rep(i, 1, n+1) cout << i << " " << 1 << endl;
    return;
  }
  n -= 30; //do n-30 then add back 30 1s instead;
  //cout << "1 1\n";
  int b = 0; //when add 2^b use b+1 line, b = 0, use 2nd
  int travel = 0; //additional done
  int side = 1; //left = 1, right = 0
  while(n)
  {
    //debug(b);
    cout << b+1 << " " << (side?1:(b+1)) << endl;
    if(n&1)
    {
      if(side) rep(i, 2, b+1+1) cout << b+1 << " " << i << endl;
      else repinv(i, 1, b+1) cout << b+1 << " " << i << endl;
      side^=1;
    }else{
      travel++; //no take but add 1, at most 30 travel
    }
    n >>= 1;
    b++;
  }
  int tofill = 30 - travel;
  rep(i, 0, tofill) cout << b+1+i << " " << (side?1:(b+1+i)) << endl; //complete the left part
  return;
}


signed main()
{
  fastIO();
  T = 1;
  cin >> T; //this
  rep(tc, 1, T+1)
  {
    cout << "Case #" << tc << ":\n"; //...
    solve();
  }
  return 0;
}
