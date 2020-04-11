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
int n;
//ll a[maxn];

//check T
void solve()
{
	cin >> n;
  vector<string> s(n);
  //vector<vector<string>> ss(n);
  rep(i, 0, n) cin >> s[i];
  string pre;
  string suf;
  vector<string> mid;
  bool ok = true;
  rep(i, 0, n)
  {
    //prefix
    //debug(i);
    int ni = s[i].size();
    int l = 0, r = ni-1;
    if(s[i][0] != '*')
    {
      while(s[i][l] != '*') l++;
      int ps = pre.size();
      int len = min(ps, l);
      rep(x, 0, len) if(s[i][x] != pre[x]) ok = false;
      if(l > ps) pre = s[i].substr(0, l);
    }
    //suffix
    if(s[i][ni-1] != '*')
    {
      while(s[i][r] != '*') r--;
      int sufs = suf.size(); //size_t to int
      int len = min(sufs, ni-1-r); //len to cmp
      rep(x, 0, len) if(s[i][ni-1-x] != suf[sufs-1-x]) ok = false; //bug
      if(ni-1-r > sufs) suf = s[i].substr(r+1, ni-1-r);
    }
    //middle
    while(l <= r)
    {
      //debug(l);
      while(s[i][l] == '*' && l < ni) l++;
      int id = l;
      while(s[i][id] != '*' && id < ni) id++;
      if(id>r) break; //touch suffix
      mid.pb(s[i].substr(l, id-l));
      l = id; //bug
    }
    //debug(i); debug(pre); debug(suf); debug(ok);
  }
  if(!ok) cout << "*\n";
  else
  {
    cout << pre;
    for(auto& x: mid) cout << x;
    cout << suf;
    cout << endl;
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

//A*B*E
//*C*D*
//A BCD E

