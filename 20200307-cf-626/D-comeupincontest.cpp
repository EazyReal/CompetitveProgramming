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
#define int ll
int T;
const int maxn = 2e5+7;
int n;

//check T

//for ith bit
// check the numbers s.t. a[0-i]+b[0-i] >= 1<<(i+1)?
void solve()
{
	cin >> n;
	vector<int> a(n);
	rep(i, 0, n) cin >> a[i];
	vector<int> r(n);
	//sort(all(a));
	int ans = 0;
	int carry = 0;
	rep(bi, 0, 30) //atmost 30 bits
	{
		//remain of last i bit
		int curv = 1<<bi;
		int nxtv = 1<<(bi+1);
		int b[2];
		b[0] = 0, b[1] = 0;
		rep(i, 0, n) r[i] = a[i]%nxtv, b[(a[i]>>bi)&1]++;
		sort(all(r));
		int sum = 0;
		rep(i, 0, n) //contribution of cary by i
		{
			int cur = r[i];
			int cfi = n-(upper_bound(all(r),nxtv-cur-1) - r.begin()); //number of will carry
			sum += cfi;
			if(cur >= curv) sum--; //no calc it self;
		}
		//debug(sum);
		assert(sum%2 == 0); //handshaking lemma
		sum /= 2;
		//if(sum%2) carry = 1; else carry = 0;
		//debug(bi);
		//debug(sum);
		int thisround = ((b[0]*b[1])&1)^carry; //use last carrys cnt and cur xor sum;
		ans |= thisround*curv;
		//debug(thisround);
		if(sum%2) carry = 1; else carry = 0; ///update carry
		//debug(carry);
	}
	cout << ans << endl;
  return;
}


signed main()
{
  fastIO();
  T = 1;
  //
	// check the numbers cin >> T; //this
  while(T--) solve();
  return 0;
}
