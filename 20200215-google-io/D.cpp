#include <bits/stdc++.h>
//WA i think is because the method required double calculation
//O(n3) should pass testcases set 1
//learn more about computaional geometry and do codebook if have time
//go convex hull/tree decompositions/algebra/string topics first

using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define repinv(i, st, n) for (int i = ((n)-1); i >= (st); --i)
#define MEM(a, b) memset(a, b, sizeof(a));

#define debug(x) std::cout << #x << ": " << x << endl
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fileIO(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

mt19937 mrand(random_device{}());
const ll mod=1e9+7;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//INT_MAX, ULLONG_MAX, LLONG_MAX or numeric_limits<int>::min()

const double	INF		= 1E200;
const double	EP		= 1E-10;
const int		MAXV	= 300;
const double	PI		= 3.14159265;

struct POINT
{
	double x;
	double y;
	POINT(double a=0, double b=0) { x=a; y=b;}
};
struct LINESEG
{
	POINT s;
	POINT e;
	LINESEG(POINT a, POINT b) { s=a; e=b;}
	LINESEG() { }
};

double dist(POINT p1,POINT p2)
{
	return( sqrt( (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y) ) );
}

double multiply(POINT sp,POINT ep,POINT op)
{
	return((sp.x-op.x)*(ep.y-op.y)-(ep.x-op.x)*(sp.y-op.y));
}

double ptoldist(POINT p,LINESEG l)
{
	return abs(multiply(p,l.e,l.s))/dist(l.s,l.e);
}

bool side_(POINT point, LINESEG l)
{
  POINT P1 = l.s;
  POINT P2 = l.e;
  return ((P2.y - P1.y) * point.x + (P1.x-P2.x) * point.y + (P2.x*P1.y - P1.x*P2.y)) > 0;
}

//------------------------------------------------------------------------//
int T;
const int maxn = mod;
int n;

void solve(int ti)
{
  cin >> n;
  vector<POINT> ps(n);
  for(auto& pi : ps) cin >> pi.x >> pi.y;
  double ans = 1e20;
  rep(i, 0, n) rep(j, i+1, n)
  {
    LINESEG ls(ps[i], ps[j]);
    vector<pair<double, int>> ds;
    rep(k, 0, n)if(k!=i && k!=j)
    {
      ds.pb(mp(ptoldist(ps[k], ls), k));
    }
    sort(all(ds));
    bool all_same_side = 1; //this was the bug i ge triggered(diff result on judge and PC)
    int p2id = -1;
    bool fir = side_(ps[ds[0].Y], ls);
    //debug(fir);
    rep(di, 0, ds.size()){ //buf ds.size() to n
      //debug(di);
      if(side_(ps[ds[di].Y], ls) != fir)
      {
        all_same_side = 0;
        p2id = di;
        break;
      }
    }
    if(!all_same_side)
    {
      ans = min(ans, (ds[p2id].X+ds[0].X)*dist(ps[i], ps[j]));
    }
  }
  cout << "Case #" << ti << ": ";
  cout << ll(ans) << endl;
  return;
}

//ptoldist(POINT p,LINESEG l)
//bool SameSide(POINT p1, POINT p2, LINE line)

signed main()
{
  fastIO();
  cin >> T;
  //T = 1;
  rep(ti, 1, T+1) solve(ti);
  return 0;
}
