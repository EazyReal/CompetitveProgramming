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
const int maxn = 1000+5;
int n;
vector<int> G[maxn];
int c[maxn];//colors

void dfs(int u)
{
  for(auto& v : G[u])
  {
    if(c[v] == -1)
    {
      c[v] = !c[u];
      dfs(v);
    }
  }
}

void solve(int ti)
{
  cin >> n;
  vector<int> a(n);
  for(auto& ai : a) cin >> ai;
  rep(i, 0, n+1) G[i].clear();
  rep(i, 1, n+1) c[i] = -1;
  //every 2 should be different
  rep(i, 0, n-(n&1))
  {
    if(!(i&1)) G[i+1].pb(i+2);//1-indexed
    if(i&1) G[i+1].pb(i);
    if(!(i&1)) G[a[i]].pb(a[i+1]);
    if(i&1) G[a[i]].pb(a[i-1]);
  }
  if(n&1) c[n] = a[0] = 0; //nth = last pick color
  else a[0] = 0;
  dfs(a[0]);
  rep(i, 1, n+1) if(c[i] == -1) {c[i]=0; dfs(i);}//fill the left with any 

  cout << "Case #" << ti << ": ";
  //rep(i, 1, n+1) cout << c[i] << endl;
  rep(i, 1, n+1) cout << "LR"[c[i]];
  cout << endl;

  return;
}


signed main()
{
  fastIO();
  cin >> T;
  //T = 1;
  rep(ti, 1, T+1) solve(ti);
  return 0;
}
