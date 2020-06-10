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
const int maxn = 2e2+7; //n, m, 100
int n, m;
//ll a[maxn];

vector<pair<pii, int>> ev;
vector<pair<pii, int>> sh;
int G[maxn][maxn];

int dis(int x, int y)
{
  pii &a = ev[x].X;
  pii &b = sh[y].X;
  return abs((a-b).X) + abs((a-b).Y);
}

//check T
void solve()
{
  //freopen("evacuate.in", "r", stdin);
  //freopen("evacuate.out", "w", stdout);

  cin >> n >> m;
  ev.resize(n);
  sh.resize(m);
  rep(i, 0, n) cin >> ev[i].X.X >> ev[i].X.Y >> ev[i].Y;
  rep(i, 0, m) cin >> sh[i].X.X >> sh[i].X.Y >> sh[i].Y;
  rep(i, 0, n) rep(j, 0, m){
    cin >> G[i][j];
    sh[j].Y -= G[i][j];
  }

  int opt = 1;
  array<int,4> swapp = {0,0,0,0};
  rep(s1, 0, n)rep(t1, 0, m) rep(s2, 0, n)rep(t2, 0, m)
  {
    if(G[s1][t1] && G[s2][t2])
    {
      if(dis(s1,t1) + dis(s2,t2) > dis(s1,t2) + dis(s2, t1)) {opt = 0; swapp = {s1,t1,s2,t2};}
    }
    if(G[s1][t1] && sh[t2].Y > 0){
      if(dis(s1,t2) < dis(s1, t1)) {opt = -1; swapp = {s1,t1,s2,t2};} 
    }
  }
  if(opt == 1)
  {
    cout << "OPTIMAL" << endl;
  }else{
    cout << "SUBOPTIMAL" << endl;
    int s1, t1, s2, t2;
    //tie(s1,t1,s2,t2) = swapp;
    s1 = swapp[0];
    t1 = swapp[1];
    s2 = swapp[2];
    t2 = swapp[3];
    if(opt == 0) {
      G[s1][t1] --;
      G[s2][t2] --;
      G[s1][t2] ++;
      G[s2][t1] ++;
    }else{
      G[s1][t1] --;
      G[s1][t2] ++;
    }
    rep(i, 0, n)rep(j, 0, m)
    {
      cout << G[i][j];
      cout << " \n"[j==m-1];
    }

  }
  return;
}


//g++ -o out -std=c++11 A.cpp

signed main()
{
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
