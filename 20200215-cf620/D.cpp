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
const int maxn = mod;
int n;
string s; //s[i] decides a[i] vs a[i+1]

inline int type2(char c)
{
  return int(c=='<');
}

void solve()
{
  cin >> n;
  cin >> s;

  vector<pii> a;
  int cnt[2]; //0:>, 1:<
  cnt[0] = cnt[1] = 0;
  int curc = 1;
  int curt = type2(s[0]);
  cnt[type2(s[0])]++;
  rep(i, 1, n-1)
  {
    cnt[type2(s[i])]++;
    if(s[i-1] == s[i]){
      curc++;
    }
    else{
      a.pb(mp(curt, curc));
      curc = 1;
      curt = 1-curt;
    }
  }
  a.pb(mp(curt, curc));//last segment
  //min part
  int cur0 = n-cnt[1]; // 53421
  int cur1 = n;//8956
  //debug(cur0);debug(cur1);
  string smin;
  smin += to_string(cur0--);
  for(auto& ai : a)
  {
    if(ai.X == 0)
    {
      rep(i, 0, ai.Y)
      {
        smin += '>'; smin += to_string(cur0--);
      }
    }else{
      cur1 -= ai.Y;
      rep(i, 1, ai.Y+1)
      {
        smin += '<'; smin +=  to_string(cur1+i);
      }
    }
  }
  //max part
  string smax;
  cout << smin << endl;
  cout << smax << endl;
  return;
}


signed main()
{
  fastIO();
  cin >> T;
  //T = 1;
  while(T--) solve();
  return 0;
}
