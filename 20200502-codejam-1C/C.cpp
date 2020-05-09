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
int n, d;
//ll a[maxn];

int ans;


//check T
void solve()
{
  cin >> n >> d;
  vector<int> a(n);
  for(auto& ai : a) cin >> ai;
  sort(all(a));
  /*int l, r, m;
  while(l < r)
  {
    if(C(a[m])) l = m;
    else r = m-1;
  }
  C(l);*/
  map<ll, int> c;
  rep(i, 0, n) c[a[i]] ++;
  for(auto it : c) {debug(it.X); debug(it.Y);}

  // 0 cut
  for(auto it : c) if(it.Y >= d){ cout << 0 << endl; return;}

  if(d == 2)
  {
    cout << 1 << endl; //2 at most 1
    return;
  }else if(d == 3)
  {
    for(auto it: c) if(c.find(it.X*2ll) != c.end()) {debug(it.X); cout << 1 << endl; return;}
    rep(i, 0, n-2) if(a[i] == a[i+1]) {cout << 1 << endl; return;}
    cout << 2 << endl; //3 at most 3
    return;
  }
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
