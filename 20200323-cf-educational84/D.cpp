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
int n;
int p[maxn];
int c[maxn];
int pk[maxn];
int id[maxn];

///use p and id to calc pk
void calc_power_of_p(int k) //max k = len p
{
	vector<int> p2(n+1);
	vector<int> ret(n+1);
	vector<int> tmp(n+1);
	rep(i, 1, n+1) p2[i] = p[i];
	rep(i, 1, n+1) ret[i] = i;
	assert(k>=0);
	for(;k>0;k>>=1){
		//debug(k);
		if(k&1)
		{
			rep(i, 1, n+1) tmp[i] = p2[ret[i]];
			rep(i, 1, n+1) ret[i] = tmp[i];
		}
		rep(i, 1, n+1) tmp[i] = p2[p2[i]];
		rep(i, 1, n+1) p2[i] = tmp[i];
	}
	rep(i, 1, n+1) pk[i] = ret[i];
	//cout << "end" << endl;
}

bool C(int x)
{
	calc_power_of_p(x);
	vector<bool> vis(n+1, 0);
	rep(i, 1, n+1) if(!vis[i])
	{
		bool flag = 1;
		int col = c[i];
		int cur = i;
		vis[cur] = 1;
		while(!vis[pk[cur]])
		{
			cur = pk[cur];
			flag &= (c[cur] == col);
			vis[cur] = 1;
		}
		if(flag) return 1;
	}
	return 0;
}

//check T
void solve()
{
	cin >> n;
	rep(i, 1, n+1) cin >> p[i];
	rep(i, 1, n+1) cin >> c[i];
	//rep(i, 1, n+1) id[i] = i;
	int L = 1, R = n, M;
	while(L < R)
	{
		M = L+R>>1;
		//debug(M);
		if(C(M)) R=M;
		else L = M+1;
	}
	cout << L << endl;
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
