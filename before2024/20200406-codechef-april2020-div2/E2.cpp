/*31335132	1 hours ago	2★maxwill	
100
[100pts]	0.21	28.7M	C++14	
View
*/
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
/*
enum ENUM{ ZERO, ONE, TWOUP};

ENUM operator++(ENUM &a)
{
    if(a == ZERO) a = ONE;
    if(a == ONE) a = TWOUP;
    if(a == TWOUP) a = TWOUP;
}

bool operator+=(ENUM &a, ENUM b)
{

}*/

//check T
void solve()
{
	cin >> n;
  vector<int> a(n, 0);
  int tmp;
  //int ans = 0;
  rep(i, 0, n)
  {
    cin >> tmp;
    while(tmp && tmp%2==0 ) tmp /= 2, a[i]++;
    if(tmp == 0) a[i] = -1;
  }
  //the power of 2 factor mater
  //how to count seg that have >= 2 factor or no 2 factor.
  //how to count seg that have only 1 2 factor
  //debug("hi");
  ll ans = n*(n+1)/2;
  for(int l = 0, r = 0; l < n && r < n; l=r+1, r=l)
  {
      while(a[r] != -1 && r < n) r++; //first 0 is at r
      debug(l);debug(r);
      if(r==l) continue;
      int len = r-l;
      map<int, int> c;
      int sum = 0;
      rep(i, 0, len) sum += a[l+i], c[sum]++; 
      //ans += len*(len+1)/2;
      int kill2 = 0;
      rep(i, 0, len)
      {
          ans -= c[1+kill2];
          kill2 += a[l+i];
      }
  }
  /*map<int, int> c;
  vector<int> s(n+1, 0);
  s[0] = a[0];
  c[a[0]]++;
  rep(i, 1, n) s[i] = s[i-1] + a[i], c[s[i]]++; 
  //rep(i, 0, n) debug(s[i]);
  //debug(c[0]); debug(c[1]);
  ll ans = n*(n+1)/2;
  int kill2 = 0;
  rep(i, 0, n)
  {
    ans -= c[1+kill2];
    kill2 += a[i];
  }*/
  cout << ans << endl;
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