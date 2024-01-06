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
int n, w, h;
vector<pii> ps;
vector<int> xs;
vector<int> ys;
//ll a[maxn];
int ans;
pii ans_cor;

bool ok(int ww, int ee, int ss, int nn)
{
  if(ee > w || ww < 0) return 0;
  if(nn > h || ss < 0) return 0;
  rep(i, 0, ps.size())
  {
    if(ps[i].X > ww && ps[i].X < ee && ps[i].Y < nn && ps[i].Y > ss) return 0;
  }
  return 1;
}

pii dxdy[4] = {{1,1}, {-1,1}, {1,-1}, {-1,-1}};

pair<int, pii> calc(int x, int y)
{
  pii best_cor;
  int maxv = -1;
  rep(i, 0, 4)
  {
    int l = 0, r = 10005, m;
    int okw, oks;
    while(l+1< r)
    {
      //debug(m);
      m = (l+r)/2;
      //debug(m);
      int x2 = x+dxdy[i].X*m;
      int y2 = y+dxdy[i].Y*m;
      int ww = min(x,x2);
      int ee = max(x,x2);
      int nn = max(y,y2);
      int ss = min(y,y2);
      if(ok(ww,ee,ss,nn))
      {
        l = m;
        oks = ss;
        okw = ww;
      }else{
        r = m;
      }
    }
    if(l > maxv)
    {
      maxv = l;
      best_cor = {okw, oks};
    }
  }
  
  return {maxv, best_cor};
}

//check T
void solve()
{
  //cin >> n; rep(i, 0, n) cin >> a[i];
  cin >> n >> w >> h;
  pii tmp;
  xs.pb(0); ys.pb(0); // add 0 0
  xs.pb(w); ys.pb(h); // add w h 
  rep(i, 0, n)
  {
    cin >> tmp.X >> tmp.Y;
    ps.pb(tmp);
    xs.pb(tmp.X);
    ys.pb(tmp.Y);
  }
  ans = 0;
  rep(i, 0, xs.size()) rep(j, 0, ys.size())
  {
    int cur;
    pii cor;
    tie(cur, cor) = calc(xs[i], ys[j]);
    if(cur >= ans)
    {
      ans = cur;
      ans_cor = cor;
    }
  }
  cout << ans_cor.X <<  " " << ans_cor.Y  << " " << ans << endl;

  return;
}


//g++ -o out -std=c++11 A.cpp

signed main()
{
#ifdef OJ
  freopen("cricket.in", "r", stdin);
  freopen("cricket.out", "w", stdout);
#endif
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
