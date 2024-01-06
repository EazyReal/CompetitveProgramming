#include <bits/stdc++.h>
//71541959	00:34:23	maxwill00:35	D - Cow and Fields	GNU C++17	Accepted	264 ms	9500 KB
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
const int maxn = 2e5+10;
int n, m, k;
vector<int> a;
vector<int> d[2];
vector<int> G[maxn];

bool cmp(const int &a, const int &b)
{
  return d[0][a] - d[1][a] <  d[0][b] - d[1][b]; //fromer =>  as 0 better
}

void bfs(int vid, int s)
{
  d[vid].resize(n);
  rep(i, 0, n) d[vid][i] = -1;
  queue<int> q;
  q.push(s);
  d[vid][s] = 0;
  while(!q.empty())
  {
    int u = q.front(); q.pop();
    for(auto&v:G[u])
    {
      if(!~d[vid][v])
      {
        d[vid][v] = d[vid][u]+1;
        q.push(v);
      }
    }
  }
}

void solve()
{
  cin >> n >> m >> k;
  a.resize(k);
  for(auto &ai : a) cin >> ai, ai--;
  int u, v;
  rep(i, 0, n) G[i].clear();
  rep(i, 0, m)
  {
    cin >> u >> v;
    G[--u].pb(--v);
    G[v].pb(u);
  }


  bfs(0, 0);
  bfs(1, n-1);

  sort(all(a), cmp);

  int cur0m = d[0][a[0]];
  int ans = INT_MIN;
  rep(i, 1, k)
  {
    ans = max(ans, cur0m + d[1][a[i]] + 1);
    cur0m = max(cur0m, d[0][a[i]]);
  }

  //rep(i, 0, n) debug(d[0][i]);
  ans = min(ans, d[0][n-1]);
  cout << ans << endl;

  return;
}

//observation : if d(a, b) == 1, adding e(a, b) wont affec anyway => optimal
//find the original optimal path
//if a, b both not on optimal path => no effect? no consider a-s-c-d-e-f-g-h-t-b

//O(n2) : dp[u] s to u and t to u dis(single source bfs), check for every pait a, b
//=> sort by d(a,s)+d(b,t) find max
//=> max d(s, a)+ max d(b, t)

//to ensure d(s, a) + d(b, t) <= d(s, b) + d(a, t)

signed main()
{
  fastIO();
  //cin >> T;
  T = 1;
  while(T--) solve();
  return 0;
}
