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

void solve(int ti)
{
  string s;
  cin >> s;
  int n = s.size();
  map<char, int> cnt;//init0 ?
  cnt['I'] = 0; cnt['i'] = 0;
  int ans = 0;
  rep(i, 0, n)
  {
    if(s[i] == 'I' || s[i] == 'i') cnt[s[i]]++;
    if(s[i] == 'O')
    {
      if(cnt['I'] > 0) ans++, cnt['I']--;
      else cnt['i']--;
    }else if(s[i] == 'o'){
      if(cnt['i'] > 0) cnt['i']--;
      else cnt['I']--;
    }
  }
  cout << "Case #" << ti << ": ";
  cout << ans << endl;
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
