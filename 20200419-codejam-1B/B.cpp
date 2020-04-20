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
int n = 1e9;
int A, B;
//ll a[maxn];

int q(int x, int y)
{
  string msg;
  int nx = x-n;
  int ny = y-n;
  if(abs(nx) > n || abs(ny) > n) return 0; //out of board
  //debug(x-n); debug(y-n);
  cout << nx << " "<< ny << endl;
  cin >> msg;
  //debug(msg);
  if(msg == "CENTER") {
    return -1;
  }
  else if(msg == "MISS") return 0;
  else if(msg == "HIT") return 1;
  else if(msg == "WRONG") exit(1);
}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int calc(int ox, int oy, int dx, int dy){
  int L = 0, R = 2e9+1, M;
  while(L+1 < R)
  {
    //debug(M);
    M = L+R >> 1;
    int mx = ox + M*dx;
    int my = oy + M*dy;
    int qr = q(mx, my);
    if(qr == -1) return -1;
    else if(qr == 1) L = M;
    else if(qr == 0) R = M;
  }
  return L;
}

//check T
int qr; //for store return
void solve()
{
  int r = 2e9/4;
  int ox = -1, oy = -1;
  rep(i, 1, 4)rep(j, 1, 4)
  {
    //debug(i*r); debug(j*r);
    int qr = q(i*r, j*r);
    if(qr == -1) return;
    else if(qr == 1){
      ox = i*r, oy = j*r;
      goto found;
    }
  }
  found:
  assert(ox != -1);
  vector<int> dis(4);
  rep(i, 0, 4)
  {
    dis[i] = calc(ox, oy, dx[i], dy[i]);
    if(dis[i] == -1) return;
  }
  int ax = ox+(dis[1]-dis[3])/2;
  int ay = oy+(dis[0]-dis[2])/2;
  debug(ax);
  debug(ay);
  qr = q(ax, ay);
  //assert(qr == -1);
  return;
}


signed main()
{
  fastIO();
  T = 1;
  cin >> T >> A >> B; //this
  rep(tc, 1, T+1)
  {
    //cout << "Case #" << tc << ": ";
    solve();
  }
  return 0;
}
