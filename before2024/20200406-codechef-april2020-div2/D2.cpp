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
const int maxn = 2e6+7;
int n;
//ll a[maxn];
int p[maxn];

void get_ptable()
{
  memset(p, 1, sizeof(p));
  p[0] = p[1] = 0;
  rep(i, 2, maxn)
  {
    if(p[i]) for(int x = i<<1; x < maxn; x+=i) p[x] = false;
  }
  return;
}

//check T
void solve()
{
	cin >> n;
  vector<bool> vis(n+5, 0);
  vector<int> ps;
  rep(i, 2, n+1) if(p[i]) ps.pb(i);
  int added = 0;
  int iter = 0;
  vector<vector<int>> ans(n+1);
  vector<int> pm(ps.size(), 1);
  ans[1].pb(1);
  added++;
  while(added < n)
  {
      iter++;
      int val;
      rep(i, 0, ps.size())
      {
          while(vis[ps[i]*pm[i]]) pm[i]++;
          val = ps[i]*pm[i];
          if(val <= n && !vis[val])
          {
              vis[val] = 1;
              ans[iter].pb(val);
              added++;
              pm[i]++;
              break;
          }
      }
      rep(i, 0, ps.size())
      {
          while(vis[ps[i]*pm[i]]) pm[i]++;
          int x = ps[i]*pm[i];
          if(x <= n && !vis[x] && gcd(x, val) == 1)
          {
              vis[x] = 1;
              ans[iter].pb(x);
              added++;
              pm[i]++;
          }
      }
      if(iter == 0) iter++;
      //debug(iter);
      //debug(added);
      //rep(i, 1, n+1) cerr << vis[i] << " \n"[i==n];
  }
  cout << iter << endl;
  rep(i, 1, iter+1)
  {
    cout << ans[i].size() << " ";
    for(int x : ans[i]) cout << x << " \n"[x==ans[i][ans[i].size()-1]];
  }
  return;
}


signed main()
{
  //fastIO();
  T = 1;
  cin >> T; //this
  get_ptable();
  rep(tc, 1, T+1)
  {
    //cout << "Case #" << tc << ": ";
    solve();
  }
  return 0;
}
