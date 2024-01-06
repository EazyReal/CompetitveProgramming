#include <bits/stdc++.h>

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

//------------------------------------------------------------------------//
int T;
const int maxn = mod;
int n, m;

typedef pair<int, pii> Customer;

void solve()
{
  cin >> n >> m;
  vector<Customer> cs(n);
  for(auto& ci : cs) cin >> ci.X >> ci.Y.X >> ci.Y.Y;
  sort(all(cs));
  int curX = m, curY = m; //cur lr = m
  int prevt = 0;
  for(int i = 0; i < n; i++)
  {
    while(i+1 < n && cs[i+1].X == cs[i].X)//deal with same time
    {
      cs[i+1].Y.X = max(cs[i+1].Y.X, cs[i].Y.X);
      cs[i+1].Y.Y = min(cs[i+1].Y.Y, cs[i].Y.Y);
      i++;
    }
    int dt = cs[i].X - prevt;
    prevt = cs[i].X;//bug
    curX = curX - dt;
    curY = curY + dt;
    //if(curY < cs[i].Y.X || curX > cs[i].Y.Y) {cout << "NO" << endl; return;} //cant reach; actually noneed
    curX = max(curX, cs[i].Y.X);
    curY = min(curY, cs[i].Y.Y);
    if(curY < curX) {cout << "NO" << endl; return;} //range = 0
    //debug(cs[i].X); debug(curX); debug(curY);
  }
  cout << "YES" << endl;
  return;
}


signed main()
{
  fastIO();
  cin >> T;
  //T = 1;
  while(T--) solve();
  return 0;
}
