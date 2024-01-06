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

int triplet, straight;
int lt, ls; //last
int qt, qs; //query
vector<int> dt, ds;
vector<int> a;

void q(int x)
{
  cout << "+ " << x << endl;
  cin >> qt >> qs;
  dt[x] = qt-lt;
  ds[x] = qs-ls;
  lt = qt, ls = qs;
  return;
}

//check T
void solve()
{
  //cin >> n; rep(i, 0, n) cin >> a[i];
  cin >> n;
  cin >> lt >> ls;
  a.assign(n+1, 0); 
  dt.assign(n+1, 0);
  ds.assign(n+1, 0);
  // n-1 ... 3 1 2 1
  repinv(i, 3, n) q(i);
  q(1); //maksure 1 non zero
  q(2); //for 2, 3
  cout << "+ " << 1 << endl;
  cin >> qt >> qs;
  int dt11 = qt-lt, ds11 = qs-ls;
  a[1] = sqrt(2*dt11); // a1 origin, 0, 1, 2up, this is to makesure a1 none zero to get a2*a3
  a[3] = ds11 - ds[1] - 1; //q1: snd  (a2+1) * (a3+1) , fst a2*(a3+1)
  a[2] = ds[1]/(a[3]+1); //fst/a3+1
  a[4] = ds[2]/(a[3]+1) - a[1]-2; //ds[2] = (a1+1)*(a3+1) + (a3+1)*(a4+1), note when calc ds2, a1 is added once
  rep(i, 5, n+1)
  {
    a[i] = (ds[i-2]-a[i-4]*a[i-3])/(a[i-1]+1)-a[i-3]-1; //calc: abcde, e from c product 
  }
  a[n]++; //a[n] is not added, +1 back
  cout << "!";
  rep(i, 1, n+1) cout << " " << a[i];
  cout << endl;
  return;
}


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
