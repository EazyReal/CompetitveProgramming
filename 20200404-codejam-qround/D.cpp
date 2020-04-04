#include <bits/stdc++.h>
//#define LOCAL
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
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); //cout.tie(0)
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
const int maxn = 1e2+7;
int n;
int a[maxn];

int sp, dp;
bool C, R;

int q(int idx)
{
  int ret;
  cout << idx+1 << endl;
  cin >> ret;
  return ret;
}

void q_pair(int idx)
{
  a[idx] = q(idx);
  a[n-1-idx] = q(n-1-idx);
  if(a[idx] == a[n-1-idx]) sp = idx;
  else dp = idx;
  return;
}

bool q_check(int idx)
{
  return a[idx] != q(idx);
}

//after quantum blabla, check changes of C, R
//
void q_change()
{
  if(sp == -1 && dp != -1)
  {
    q(0);
    if(q_check(dp)) C = 1, R = 0;
    else C = 0, R = 0;
  }else if(dp == -1 && sp != -1)
  {
    q(0);
    if(q_check(sp)) C = 1, R = 0;
    else C = 0, R = 0;
  }else if(sp != -1 && dp != -1)
  {
    bool spc = q_check(sp);
    bool dpc = q_check(dp);
    C = spc;
    R = dpc^spc;
  }else{
    assert(0);
  }
  if(C) rep(i, 0, n) a[i] = 1 - a[i];
  if(R) rep(i, 0, n/2) swap(a[i], a[n-1-i]);
  return;
}

//check T
void solve()
{
  int id = 0; //current id, assert <= n/2
  sp = -1, dp = -1; //same_pair, diff_pair
  //n >= 0 and n in {10, 20, 100}, no need to consider smaller or not divisible by 2
  rep(i, 0, 5)
  {
    q_pair(id++); //10q
  }
  //rep(k, 0, n) cout << a[k]; cout << endl;
  while((id-1) + 1 < n-1-(id-1))
  {
    q_change(); //2q
    //rep(i, 0, n) cout << a[i]; cout << endl;
    rep(i, 0, 4) q_pair(id++); //8q
    //rep(k, 0, n) cout << a[k]; cout << endl;
  }
  //answer
  rep(i, 0, n) cout << a[i]; cout << endl;
  char result;
  cin >> result;
  if(result == 'N') exit(0);
  else return;
}


signed main()
{
  fastIO();
  T = 1;
  cin >> T >> n; //this
  rep(tc, 1, T+1)
  {
    //out << "Case #" << tc << ": ";
    solve();
  }
  return 0;
}
