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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

//mt19937 mrand(random_device{}());
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
ll n;
ll p;
string str;
ll s[maxn];

//check T
void solve()
{
	cin >> n >> p;
	cin >> str;
	rep(i, 0, n) s[i] = str[i]-'0';
	if(p == 2)
	{
		ll ans = 0;
		rep(i, 0, n) if(s[i]%2 == 0) ans += (i+1);
		cout << ans << endl;
		return;
	}
	if(p == 5)
	{
		ll ans = 0;
		rep(i, 0, n) if(s[i]%5 == 0) ans += (i+1);
		cout << ans << endl;
		return;
	}
	//suf[i] === suf[j] mod p
	map<ll, ll> cnt;
	++cnt[0];
	ll ans = 0;
	int suf = 0, p10 = 1;
	repinv(i, 0, n)
	{
		suf = (suf + s[i]*p10)%p;
		ans += cnt[suf]++;
		p10 = p10 *10%p;
	}
	cout << ans << endl;
  return;
}


signed main()
{
  fastIO();
  T = 1;
  //cin >> T; //this
  while(T--) solve();
  return 0;
}
