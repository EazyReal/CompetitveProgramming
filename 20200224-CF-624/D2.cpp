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

//10000 get hacked
//test case9
//1 137 10000 10000
//137 10001 10001
//~nlogn by n+n/2+n/3+n/4...
//should write decide c version to ensure nlogn
//maybe try fix B version

int T; //100
const int maxn = 5e5+5;
int a, b, c; //1e4

inline bool ok(int a, int b, int c)
{
	return (b%a == 0) && (c%b == 0);
}

int cost(int ca, int cb, int cc)
{
	return abs(a-ca) + abs(b-cb) + abs(c-cc);
}

void solve()
{
	cin >> a >> b >> c;
	int ta, tb, tc;
	int aa = 1, ab = 1, ac = 1; //ans
	int minv = (a-1)+(b-1)+(c-1); //min
	/*rep(i, 1, 1e4+1) //a range
	{
		ta = i;
		int modba = b%ta;
		int nba =
		if(modba == 0) tb = b;
		else if
	}*/
	for(ta = 1; ta <= 10000; ta++)
	{
		//int closemaxb = c;
		//int closemaxb = (b/ta)*ta + ta;
		for(tb = ta; tb <= 20000; tb += ta) //tb >= ta && tb%ta = 0
		{
			//int closemaxc = 10000;
			//int closemaxc = (c/tb)*tb + tb;
			for(tc = tb; tc <= 20000; tc += tb) //tc >= tb && tc%tb = 0
			{
				assert(ok(ta, tb, tc));
				if(cost(ta, tb, tc) < minv)
				{
					aa = ta, ab = tb, ac = tc;
					minv = cost(aa, ab, ac);
				}
			}
		}
	}
	cout << minv << endl;
	cout << aa << ' ' << ab << ' ' << ac << ' ' << endl;

  return;
}
//1 10000 10000 TLE X

signed main()
{
  fastIO();
  cin >> T;
  //T = 1;
  while(T--) solve();
  return 0;
}
