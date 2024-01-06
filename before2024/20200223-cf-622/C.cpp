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

inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}

//------------------------------------------------------------------------//
int T;
const int maxn = 5e5+7;
int n;
int a[maxn];
int b[maxn];
int ans[maxn];

//O(n) enum mid//highiest point

void solve()
{
	cin >> n;
	rep(i, 1, n+1) cin >> a[i];
	ll best = -1;
	rep(M, 1, n+1)
	{
		ll sum = a[M];
		b[M] = a[M];
		int curv = a[M];
		repinv(i, 1, M)
		{
			b[i] = min(a[i], curv);
			curv = min(curv, b[i]);
			sum += b[i];
		}
		curv = a[M];
		rep(i, M+1, n+1)
		{
			b[i] = min(a[i], curv);
			curv = min(curv, b[i]);
			sum += b[i];
		}
		//cout << "case " << M << endl;
		//rep(i, 1, n+1) cout << b[i] << " \n"[i==n];
		if(sum > best) {rep(i, 1, n+1) ans[i] = b[i]; best = sum;}
	}
	rep(i, 1, n+1) cout << ans[i] << " \n"[i==n];
  return;
}


signed main()
{
  fastIO();
  //cin >> T;
  T = 1;
  while(T--) solve();
  return 0;
}
