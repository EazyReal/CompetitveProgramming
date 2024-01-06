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
int p[maxn];
int c[maxn];
vi factor[maxn];

//complexity sigma #factor[i]*i, sigma i = n 

void calc_factor()
{
  rep(i, 1, maxn) //1 does matter!
  for(int j = i; j < maxn; j += i)
    factor[j].pb(i);
  //rep(i, 1, maxn) reverse(all(factor[i]));//from big to small
}

bool C(vi cycle, int x) //pass by value, x is step size
{
  int l = cycle.size();
  rep(start, 0, x)
  {
    bool flag = 1;
		int col = c[cycle[start]];
    int idx = start;
    int tl = l/x;
    rep(i, 0, tl)
    {
      idx = (idx+x)%l;
      flag &= c[cycle[idx]] == col;
    }
    if(flag) return 1;
  }
  return 0;
}

void solve()
{
	cin >> n;
	rep(i, 1, n+1) cin >> p[i];
	rep(i, 1, n+1) cin >> c[i];
  int ans = n;
  vector<bool> vis(n+1, 0);
	rep(i, 1, n+1) if(!vis[i])
	{
		int cur = i;
    int l = 1;
		vis[cur] = 1;
    vi cycle(1, cur);
		while(!vis[p[cur]])
		{
      cur = p[cur];
      l++;
      cycle.pb(cur);
			vis[cur] = 1;
		}
    for(int x:factor[l])if(x < ans && C(cycle, x))
    {
      ans = min(ans, x);
      break;
    }
	}
  cout << ans << endl;
  return;
}


signed main()
{
  fastIO();
  calc_factor();
  T = 1;
  cin >> T; //this
  while(T--) solve();
  return 0;
}
