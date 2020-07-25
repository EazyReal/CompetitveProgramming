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

int f(int s, int k, int d) //k num
{
  return (s+s+(k-1)*d)*(k)/2;
}

int findi(int d)
{
  int l = 0, r = 3*1e9, m;
  while(l < r-1) //[)
  {
    int m = (l+r)/2;
    //debug(l); debug(r); debug(m);
    int v = m*(m+1)/2;
    if(v <= d) l = m; //find st l*l+1/2 <= d, use l+1
    else r = m;
  }
  return l;
}

int find2(int mm, int start)
{
  if(start > mm) return start-2;
  int l = 0, r = 3*1e9, m;
  while(l < r-1) //[)
  {
    int m = (l+r)/2;
    //debug(l); debug(r); debug(m);
    int v = (start+start+2*m)*(m+1)/2;
    if(v <= mm) l = m; //find st l*l+1/2 <= d, use l+1
    else r = m;
  }
  return start+2*l;
}


//check T
void solve()
{
  int l, r;
  int n = 1;
  cin >> l >> r;

  /*while(1)
  {
    if(l < n && r < n) break; // not enough end
    int d = abs(l-r);
    if(l >= r)
    {

    }else{

    }
  }*/
  bool flag = 0;
  bool flag2 = 0;
  if(l < r) {swap(l, r); flag = 1;}
  int d = abs(l-r);
  n = findi(d);
  l -= f(1, n, 1); // 1 to n 
  if(l == r) { flag = 0;} //always picl l first regardless origin
  //debug(n); debug(l); debug(r);
  int ml = find2(l, n+1);
  int mr = find2(r, n+2);
  //debug(ml); debug(mr);
  l -= (ml+n+1)/2*((ml-n-1)/2+1); //can /2 same parity
  r -= (mr+n+2)/2*((mr-n-2)/2+1);
  n = max(ml, mr);

  if(flag) swap(l, r);
  //if(flag2 && l > r) swap(l, r);
  cout << n << " " << l << " " << r << endl;
  return;
}


signed main()
{
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
