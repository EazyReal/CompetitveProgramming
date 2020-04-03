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
//int vis[maxn];

//check T
void solve()
{
  cin >> n;
  vector<int> a(n+2);
  vector<int> vis(n+2);
  //vector<int> s();
  rep(i, 1, n+1) vis[i] = 0;
  vector<vi> occ(n+1);
  bool flag = 0;
  rep(i, 1, n+1)
  {
      cin >> a[i]; 
      vis[a[i]] = 1;
      occ[a[i]].pb(i);
      if(occ[a[i]].size() > 2)
      {
          flag = 1;
      }
  }
  if(flag){
      cout << 0 << endl;
      return;
  }
  vector<pii> ans;
  int l = 0, r = n+1;
  int id = 1;
  while(occ[id].size() == 2)
  {
      int locc = min(occ[id][0], occ[id][1]);
      int rocc = max(occ[id][0], occ[id][1]);
      l = max(l, locc);
      r = min(r, rocc);
      id++;
  }
  id--;
  int another = n-id;
  if(id == 0){
      cout << 0 << endl;
      return;
  }
  rep(i, 1, n+1) vis[i] = 0;
  if((n-r+1) == id)
  {
      int uniq = 0;
      rep(i, 1, r)
      {
          if(a[i] >= 1 && a[i] <= another && !vis[a[i]])
          {
              uniq ++;
              vis[a[i]] = 1;
          }
      }
      if(uniq == another)
      {
          ans.pb(mp(n-id, id));
      }
  }
  rep(i, 1, n+1) vis[i] = 0;
  if(l == id)
  {
      int uniq = 0;
      rep(i, l+1, n+1)
      {
          if(a[i] >= 1 && a[i] <= another && !vis[a[i]])
          {
              uniq ++;
              vis[a[i]] = 1;
          }
      }
      if(uniq == another)
      {
          ans.pb(mp(l, n-l));
      }
  }
  
  if(ans.size() == 2 && ans[1] == ans[0]) ans.resize(1);
  cout << ans.size() << endl;
  rep(i, 0, ans.size()) cout << ans[i].X << ' ' << ans[i].Y << endl;

  return;
}


signed main()
{
  fastIO();
  T = 1;
  cin >> T; //this
  while(T--) solve();
  return 0;
}
