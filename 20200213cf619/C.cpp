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
#define NL << endl

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

typedef unsigned long long ull;

int T;
ull n, m;

//ans <= ll 10^18
void solve()
{
  cin >> n >> m;

  ll allp = (n+1)*n/2ull;
  ll ze = n-m;
  ll part = m+1;
  ll mean = ze/part;
  ll more = ze%part;
  ll nomore = part-more;
  ll formean = mean*(mean+1)/2;
  ll formore = (mean+1)*(mean+2)/2;
  ll allno = nomore*formean + more*formore;
  cout << allp - allno << endl;
  return;
}

signed main()
{
  fastIO();
  cin >> T; // T = 1;
  while(T--) solve();
  return 0;
}
