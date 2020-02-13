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

#define int ll
mt19937 mrand(random_device{}());
const ll mod=1e9+7;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//INT_MAX, ULLONG_MAX, LLONG_MAX or numeric_limits<int>::min()

//------------------------------------------------------------------------//
int T;
int n;
const int maxn = 1e5+5;
int a[maxn];

void solve()
{
  cin >> n;
  vector<int> s;
  a[0] = -2; //...
  a[n+1] = -2;
  rep(i, 1, n+1)  cin >> a[i];
  rep(i, 1, n+1) if((a[i-1]==-1 || a[i+1] == -1) && a[i]!=-1) s.pb(a[i]);
  int natural = 0;
  rep(i, 1, n) if(a[i] != -1 && a[i+1] != -1) natural = max(natural, abs(a[i+1]-a[i]));
  if(s.size() == 0) cout << natural << " 0" << endl; //only all -1 => natural 0
  else{
    sort(all(s));
    int minv = s[0], maxv = s[s.size()-1];
    int k = (maxv+minv)/2;
    assert(minv != -1 && maxv != -1);
    //int minv = *s.begin(), maxv = *s.rbegin();
    int choose = max(maxv-k, k-minv);
    cout << max(choose, natural) << ' ' << k << endl;
  }
  return;
}


signed main()
{
  fastIO();
  cin >> T; // T = 1;
  while(T--) solve();
  return 0;
}
