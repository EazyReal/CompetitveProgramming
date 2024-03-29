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
int n, k;
//ll a[maxn];
vector<int> cnt;
vector<int> c; //constraint
vector<int> TC[maxn];
int used[maxn]; //

bool C(int x)
{
  rep(i, 0, x) TC[i].clear(); //O(n)
  rep(i, 0, x) used[i] = 0;   //O(n)

  //k*n if used[i] is all full
  repinv(num, 1, k+1) //O(k)
  {
    int cn = cnt[num];
    rep(i, 0, x)
    {
      if(cn == 0) break;
      while(cn > 0 && c[num]-used[i] > 0)
      {
        TC[i].pb(num);
        used[i]++;
        cn--;
      }
    }
    if(cn > 0) return 0;
  }
  return 1;
}

//check T
void solve()
{
  cin >> n >> k;
  int tmp;
  cnt.assign(k+1, 0);
  rep(i, 0, n)
  {
    cin >> tmp;
    cnt[tmp]++;
  }
  c.assign(k+1, 0);
  rep(i, 1, k+1) cin >> c[i];
  //int ans = 0;
  //rep(i, 1, k+1) ans = max(ans, (cnt[i]+c[i]-1)/c[i]);
  int L = 1, R = n, M;
  while(L < R)
  {
    int M = L+R >> 1;
    debug(M);
    if(C(M)) R = M;
    else L = M+1;
  }
  cout << L << endl;
  C(L);
  rep(i, 0, L)
  {
    cout << TC[i].size();
    rep(j, 0, TC[i].size()) cout << " " << TC[i][j];
    cout << endl;
  }

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
