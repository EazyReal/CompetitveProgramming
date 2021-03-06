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
int T;
const int maxn = 2e5+7;
int n;
string s;
char a[maxn];

bool C(int x)
{
	vector<int> mark(n+100, 0);
	queue<int> q;
	q.push(0); //q.push(mp(n+1, 2));
	mark[0] = 1;
	while(!q.empty())
	{
		int cur = q.front(); q.pop();
		if(cur == n+1) return 1;
		rep(di, 1, x+1) //TLE
		{
			int dir = (a[cur] == 'R') ? 1 : -1;
			int nxt = cur + dir*di;
			if(nxt == n+1) return 1;

			if(nxt < 0 || nxt > n+1) break; //?
			else if(mark[nxt]) continue;
			else {
				mark[nxt] = 1;
				q.push(nxt);
			}
		}
	}
	return 0;
}

//check T
void solve()
{
	cin >> s;
	n = s.size();
	rep(i, 1, n+1) a[i] = s[i-1];
	a[0] = 'R'; a[n+1] = 'L';
	//rep(i, 0, n+2) cout << a[i];
	//rep(i, 1, n+2) cout << i << ' ' << C(i) << endl;

	int L = 1, R = n+1;
	int M;
	while(L+1 < R)
	{
		M = (L+R)>>1;
		//cout << M <<endl;
		if(C(M)) R = M; //M-1 ok
		else L = M;
	}
	//cout << L << endl;
	int ans;
	int l = max(1, L-2);
	int r = min(n+2, L+2);
	rep(x, l, r) {if(C(x)) {ans = x; break;}}
	//rep(i, 1, n+2) cout << i << ' ' << C(i) << endl;
	cout << ans << endl;

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
