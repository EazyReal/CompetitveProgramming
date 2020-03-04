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
int n;
string s;

//check T
void solve()
{
	cin >> n;
	cin >> s;
	set<pair<string, int> > st;
	if(n == 1) {cout << s << endl << 1 << endl; return;}
	rep(k, 1, n+1)
	{
		string a(n,'0');
		//rep(i, 0, n-k+1) a[i] = s[i];
		//rep(i, 0, k-1) a[n-1-i] = s[n-k+1+i];
		if(k == 1) {st.insert(mp(s, 1)); continue;}
		rep(i, k-1, n) a[i-k+1] = s[i];
		//reverse
		if((n-k+1)%2 == 1)
		rep(i, 0, k-1) a[n-k+1+i] = s[k-1-1-i];
		else
		rep(i, 0, k-1) a[n-k+1+i] = s[i];
		//debug(a);
		st.insert(mp(a, k));
	}
	cout << (*st.begin()).X << endl << (*st.begin()).Y << endl;
  return;
}


signed main()
{
  fastIO();
  T = 1;
  cin >> T; //this
  while(T--) solve();
  return 0;
}