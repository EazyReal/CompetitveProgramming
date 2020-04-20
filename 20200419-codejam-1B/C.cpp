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
int r, s;

//check T
void solve()
{
  cin >> r >> s;
  int limit = (r*s-r+1)/2; //ceiling
  cout << limit << endl;
  vector<pii> cards[2];
  int cur = 0;
  #define nxt (1-cur)
  rep(j, 0, s)rep(i, 0, r) cards[cur].pb(mp(i, 1));
  rep(round, 0, limit)
  {
    int n = cards[cur].size();
    int c1 = cards[cur][0].X;
    int c2 = -1;
    int m1, m2; //mark
    rep(i, 1, n) if(cards[cur][i].X == c1) {m2 = i+1, c2 = cards[cur][m2].X; break;}
    if(m2 == n) m1 = 1; //ABCA, 3123
    else{
      rep(i, 0, n) if(cards[cur][i].X == c2) {m1 = i+1; break;}
    }
    // c1, c2 is determined
    //debug(m1);debug(m2);
    int s1 = 0, s2 = 0;
    rep(i, 0, m1) s1 += cards[cur][i].Y;
    rep(i, m1, m2) s2 += cards[cur][i].Y;
    cout << s1 << " " << s2 << endl;
    vector<int> p(n);
    int cnt = 0;
    rep(i, m1, m2)  p[cnt++] = i;
    rep(i, 0, m1)  p[cnt++] = i;
    rep(i, m2, n)  p[cnt++] = i;
    int prev = -1;
    int sum = 0;
    rep(k, 0, n)
    {
      int i = p[k];
      if(cards[cur][i].X == prev) sum += cards[cur][i].Y;
      else
      {
        if(prev != -1) cards[nxt].pb(mp(prev, sum)); //not else if ..
        sum = cards[cur][i].Y;
        prev = cards[cur][i].X;
      }
    }
    if(prev != -1) cards[nxt].pb(mp(prev, sum));
    /*rep(i, 0, cards[nxt].size())
    {
      cerr << cards[nxt][i].X << " " << cards[nxt][i].Y << endl;
    }*/
    cur = nxt;
    cards[nxt].clear(); //the nxt now is not the last nxt, all nxt is correspend to cur
  }
  return;
}


signed main()
{
  fastIO();
  T = 1;
  cin >> T; //this
  rep(tc, 1, T+1)
  {
    cout << "Case #" << tc << ": ";
    solve();
  }
  return 0;
}
