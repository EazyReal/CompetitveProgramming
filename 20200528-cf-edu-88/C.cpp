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
#define int ll
int T;
const int maxn = 2e5+7;
int n;
//ll a[maxn];
int h,c,t;

double calc(int i)
{
  double  val = 1.0*((i+1)*h + i*c)/(2*i+1);
  double tt = t;
  debug(val);
  return  (val-tt <0) ? tt-val : val-tt;
}

/*
bool cmp(int i, int j)
{
  int d1 = (i+1)*h + i*c;
  int n1 =  t*(2*i)+1;

  int d2 = (j+1)*h + j*c;
  int n2 =  t*(2*j)+1;

  return 2*n1*n2*t < n1*d2 + n2*d1; //overflow
}
*/

/*
bool lt(int i) //total = 2*l+1
{
  double val = 1.0*((i+1.0)*h + i*c)/(2.0*i+1.0);
  //debug(val);
  //debug(double(t));
  return val < double(t);
}
*/

bool lti(int i) //total = 2*l+1
{
  int val = (i+1)*h + i*c;
  return val < t*(2*i+1);
}

//check T
void solve()
{
  //cin >> n; rep(i, 0, n) cin >> a[i];
  cin >> h >> c >> t;
  if(t >= h) {cout << 1 << endl; return;}
  else if(t <= (h+c)/2) { cout << 2 << endl; return;} //decrease to  if <= => use 2
   /*cout << endl;
  rep(i, 1, 13)
  {
    cout << i << " ";
    cout << 1.0*((i+1)*h + i*c)/(2*i+1) << endl;
  }*/

  int L = 1, R = 1000000; //L = exact reach < 
  while(L <= R) // [L, R]
  {
    int M = (L+R)/2;
    if(lti(M)) R = M-1; //not < , bigger l
    else L = M+1; //>=, smaller 
  } 
  //if((L-1, L)) cout << 2*L-1 << endl;
  if(calc(L-1)<= calc(L)) cout << 2*L-1 << endl;
  else cout << 2*L+1 << endl;
  //cout << "hi" << calc(4500);
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
