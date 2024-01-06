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
const int maxb = 32; //maxb+1
int n;
int x, y;
bool rx, ry; //reverse output mark
string ans; //vector char
/*
int is_p2m1(int x)
{
  int cnt = 0;
  while(x && (!(x&1))) x >>= 1; //remove tail 0
  while(x)
  {
    if(x&1)
    {
      x >>= 1;
      cnt++;
    }else //x is not 0 but x has no bit i
    {
      return 0;
    }
  }
  return cnt;
}
*/
//__builtin_ctz(x) tail 0

//check T
void solve()
{
  cin >> x >> y;

  if(x < 0) {rx = true; x = -x;}
  else rx = false;

  if(y < 0) {ry = true; y = -y;}
  else ry = false;

  ans.clear();
  //if 0, 1 ok
  //if 0, 0 borrow last
  //if 1, 1 go till no 1 1, nxt need to be 0, 0, and go nxt


#define nxtx (x>>1&1)
#define nxty (y>>1&1)

  int last1 = -1; // last 1 is 0 => x, 1 => y, -1 => none
  int cnt = 0;
  while(x || y) // x or y is non zero, continue
  {
    cnt++;
    //debug(cnt); // i th lopp 1 indexed
    int xx = x&1;
    int yy = y&1;

    if(xx && !yy)
    {
      last1 = 0;
      ans.pb('E');
    }else if(!xx && yy)
    {
      last1 = 1;
      ans.pb('N');
    }else if(!xx && !yy)
    {
      if(last1 == -1) { cout << "IMPOSSIBLE" << endl; return;}
      ans.pop_back();
      if(last1 == 0) { ans.pb('W'); ans.pb('E'); }
      else { ans.pb('S'); ans.pb('N'); }
      /*
      rep(k, 0, ans.size())
      {
        char &c = ans[k];
        if(c == 'E' || c=='W') if(last1 == 0)
        {
          if(c == 'W') c = 'E'; else c = 'W';
        }
        if(c == 'N' || c=='S') if(last1 == 1)
        {
          if(c == 'N') c = 'S'; else c = 'N';
        }
      }
      */
      last1 = last1; //nug 20min
    }else if(xx && yy) //use last 1
    {
      if(last1 == -1) { cout << "IMPOSSIBLE" << endl; return;}
      ans.pop_back();
      if(last1 == 0) ans.pb('W'); else ans.pb('S');
      /*rep(k, 0, ans.size())
      {
        char &c = ans[k];
        if(c == 'E' || c=='W') if(last1 == 0)
        {
          if(c == 'W') c = 'E'; else c = 'W';
        }
        if(c == 'N' || c=='S') if(last1 == 1)
        {
          if(c == 'N') c = 'S'; else c = 'N';
        }
      }*/
      
      if(last1 == 0){
        x++;
      }
      else{
        y++;
      }
      last1 = 1 - last1;
      if(last1 == 0) ans.pb('E'); else ans.pb('N');
      /*
      while(xx && yy) 
      {
        x >>= 1;
        y >>= 1;
        xx = x&1;
        yy = y&1;
        if(last1 == 0) ans.pb('N'); else ans.pb('E');
      }
      if(!xx && !yy) {if(last1 == 0) ans.pb('E'); else ans.pb('N');}
      else { cout << "IMPOSSIBLE" << endl; return;}
      last1 = -1;
      */
    }

    x >>= 1;
    y >>= 1; 
  }

  //check inverse
  rep(i, 0, ans.size())
  {
    char c = ans[i];
    if(c == 'E' || c=='W') if(rx)
    {
      if(c == 'W') c = 'E'; else c = 'W';
    }
    if(c == 'N' || c=='S') if(ry)
    {
      if(c == 'N') c = 'S'; else c = 'N';
    }
    cout << c;
  }
  cout << endl;

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
