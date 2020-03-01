//72138977	Mar/01/2020 15:34UTC+8	maxwill	F - Super Jaber	GNU C++17	Accepted	2277 ms	201900 KB

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
pii operator+(const pii&x, const pii&y) { return mp(x.X+y.X, x.Y+y.Y);}
pii operator-(const pii&x, const pii&y) { return mp(x.X-y.X, x.Y-y.Y);}
//INT_MAX, ULLONG_MAX, LLONG_MAX or numeric_limits<int>::min()

//------------------------------------------------------------------------//

int T;
int n, m, k;
const int maxn = 1000+5;
const int maxc = 40+5;
int a[maxn][maxn];
vector<pii> G[maxc];
pii dxy[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int d[maxc][maxn*maxn];

//*m debug 10min up...
inline id(int x, int y){return x*m+y;}
inline id(pii p){return p.X*m+p.Y;}
inline bool inrange(pii v){return 0 <= v.X && v.X < n && 0 <= v.Y && v.Y < m;}

void bfs(int c) //force pass by reference, maybe name collision causing not updating outside val
{
  //int (&d[c])[maxn*maxn] = d[c];
  //debug(c);
  memset(d[c], -1, sizeof(d[c]));
  queue<pii> q;
  vector<bool> used(k+1, 0); //remember jumps
  used[c] = 1; //no jumps on cur color
  for(pii &u:G[c])
  {
    q.push(u);
    d[c][id(u)] = 0;
  }
  while(!q.empty())
  {
    pii  cur = q.front(); q.pop();
    int curc = a[cur.X][cur.Y];
    int nxtd = d[c][id(cur)]+1;
    //debug(nxtd);
    if(!used[curc])
    {
      for(pii &v : G[curc]) if(d[c][id(v)] == -1)
      {
        q.push(v);
        d[c][id(v)] = nxtd;
      }
      used[curc] = 1;
    }
    for(pii &di : dxy)
    {
      pii v = cur + di;
      if(inrange(v) && d[c][id(v)] == -1)
      {
        q.push(v);
        d[c][id(v)] = nxtd;
      }
    }
  }
}

void solve()
{
  cin >> n >> m >> k;
  rep(i, 0, n)rep(j, 0, m) cin >> a[i][j], G[a[i][j]].pb(mp(i, j));

  rep(i, 1, k+1) bfs(i); //gerantee has at least one;
  //print
  /*rep(ki, 1, k+1)
  {
    debug(ki);
    rep(i, 0, n)rep(j, 0, m) cout << d[ki][i*n+j] << " \n"[j==m-1];
  }*/
  int q;  cin >> q;
  int x1, y1, x2, y2;
  rep(i, 0, q)
  {
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    int ans = abs(x1-x2) + abs(y1-y2); //no jump
    rep(ki, 1, k+1) ans = min(ans, d[ki][id(x1, y1)] + d[ki][id(x2, y2)] + 1); //forget +1 jump
    cout << ans << endl;
  }
  return;
}

signed main()
{
  fastIO();
  T = 1;
  //cin >> T;
  while(T--) solve();
  return 0;
}
