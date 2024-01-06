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
#define int ll
#define ull ll
int T;
const int maxn = 2e5+7;
int n;

const int MAX_STEP = 15;
const int Z = 3;
const int ZZ = Z * Z;
const ull ROW_MASK = 0x1fffffll;
const ull ITEM_MASK = 0x7fll;
const int ROW_BIT_LEN = 21;
const int ITEM_BIT_LEN = 7;
const int MAX_H = 100;

ull swapRow(ull s, int r0, int r1) {
    ull rr0 = ((s >> (r0 * ROW_BIT_LEN)) & ROW_MASK);
    ull rr1 = ((s >> (r1 * ROW_BIT_LEN)) & ROW_MASK);
    s &= ~(ROW_MASK << (r0 * ROW_BIT_LEN));
    s &= ~(ROW_MASK << (r1 * ROW_BIT_LEN));
    s |= (rr0 << (r1 * ROW_BIT_LEN));
    s |= (rr1 << (r0 * ROW_BIT_LEN));
    return s;
}

ull swapCol(ull s, int r0, int r1) {
    ull rows[Z];
    for (int i = 0; i < Z; i++) {
        rows[i] = (s & ROW_MASK);
        s >>= ROW_BIT_LEN;
    }
    for (ull& b : rows) {
        ull cc0 = ((b >> (r0 * ITEM_BIT_LEN)) & ITEM_MASK);
        ull cc1 = ((b >> (r1 * ITEM_BIT_LEN)) & ITEM_MASK);
        b &= ~(ITEM_MASK << (r0 * ITEM_BIT_LEN));
        b &= ~(ITEM_MASK << (r1 * ITEM_BIT_LEN));
        b |= (cc0 << (r1 * ITEM_BIT_LEN));
        b |= (cc1 << (r0 * ITEM_BIT_LEN));
    }
    for (int i = Z - 1; i >= 0; i--) {
        s <<= ROW_BIT_LEN;
        s |= rows[i];
    }
    return s;
}

void dfs(int v, int f, int d, unordered_map<int, int>  ht)
{
  //debug(v); debug(d);
  if(d > 8) return;
  if(ht.find(v) == ht.end()) ht[v] = d;
  else ht[v] = min(ht[v], d);

  vector<int> todo = {
    v,
    swapRow(v, 0, 1),
    swapRow(v, 0, 2),
    swapRow(v, 1, 2),
    swapCol(v, 0, 1),
    swapCol(v, 0, 2),
    swapCol(v, 1, 2),
  };


  for( auto &x : todo)
  {
    int nxt = x+f;
    if(d+1 <= 8 && (ht.find(nxt)==ht.end() || (ht.find(nxt)!=ht.end()&& ht[nxt]>d+1 ))) dfs(nxt, f, d+1, ht);
  }

  return ;

}



//check T
void solve()
{
  //cin >> n; rep(i, 0, n) cin >> a[i];
  int x;
  //int a, b;
  //rep(i, 0, 9) cin >> x, a += x, a*=100;
  //rep(i, 0, 9) cin >> x, b += x, b*=100;
  ll fire = 0;
    for (int i = 0; i < ZZ; i++) {
        int a;
        cin >> a;
        fire <<= ITEM_BIT_LEN;
        fire |= a;
    }
    ll d = 0;
    for (int i = 0; i < ZZ; i++) {
        int a;
        cin >> a;
        d <<= ITEM_BIT_LEN;
        d |= a;
    }
  
  unordered_map<int, int> vis[2];
  vis[0][0] = 0;
  vis[1][d] = 0;
  dfs(0, fire, 0, vis[0]); //state, depth, start
  dfs(d, -fire, 0, vis[1]);

  int ans = 20;
  for(auto it = vis[0].begin(); it != vis[0].end(); it++ )
  {
    int v = it->X;
    if(vis[1].find(v) != vis[1].end())
    {
      debug(it->Y);
      debug(vis[1][v]);
      ans = min(ans, it->Y + vis[1][v]);
    }
  }
  if(ans < 20) cout << ans << endl;
  else cout << "NA IS HARD, SO IS LIFE.\n";


  
  return;
}


signed main()
{
  fastIO();
  T = 1;
  cin >> T; //this
  rep(tc, 1, T+1)
  {
    //cout << "Case #" << tc << ": ";
    solve();
  }
  return 0;
}
