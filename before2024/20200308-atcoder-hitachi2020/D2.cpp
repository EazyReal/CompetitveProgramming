#include <bits/stdc++.h>
//#define LOCAL
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
const int maxn = 2e5+7;
int n;
ll T;
//ll a[maxn];
vector<pll> a;
ll t[maxn];
ll p[maxn];
//check T

bool cmp2(int x, int y)
{
	return a[x].X > a[y].X; //m bigger choose first
}

bool C(int x)
{
	ll t = 0;
	ll Ttmp = T;
	vector<int> pc(x);
	rep(i, 0, x) pc[i] = p[i]; //deadline later first => for other time more
	sort(all(pc), cmp2); //wait more first
	rep(i, 0, x)
	{
		t++;
		//Ttmp--;
		t += a[pc[i]].X*t+a[pc[i]].Y;
		//Ttmp -=
		if(t > T) return 0;
	}
	return t <= T;
}

bool cmp(int x, int y)
{
	//if((T-a[x].Y) * (a[y].X+1) > (T-a[y].Y) * (a[x].X+1) ) return 1; //deadline
	//else if((T-a[x].Y) * (a[y].X+1) == (T-a[y].Y) * (a[x].X+1) ) return a[x].X < a[y].X;
	//return 0;
	if(t[x] > t[y]) return 1;
	return t[x]==t[y] && a[x].X<a[x].X;
}

void solve()
{
	cin >> n >> T;
	a.resize(n);
	rep(i, 0, n) cin >> a[i].X >> a[i].Y;
	rep(i, 0, n) t[i] = max(-1ll, (T-a[i].Y-a[i].X-1)/(a[i].X+1)); // T' = for other's time
	//T' is to calc T''
	rep(i, 0, n) p[i] = i;
	sort(p, p+n, cmp);
	//rep(i, 0, n) cout << p[i] << " \n"[i==n-1];
	int L = 0, R = n+1, M;
	while(L+1 < R)
	{
		M = (L+R)/2;
		if(C(M)) L = M;
		else R = M; //cannot => upperbound low
	}
	cout << L << endl;
  return;
}


signed main()
{
  fastIO();
  solve();
  return 0;
}

/*
 1000000
10000000000 10000000000
10000000000 10000000000
10000000000 10000000000
10000000000 10000000000
10000000000 10000000000
*/
/*
5
1000000000
100000000
100000000
100000000
100000000
100000000
100000000
100000000
100000000
100000000
100000000
*/
