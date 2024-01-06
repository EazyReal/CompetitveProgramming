#include <bits/stdc++.h>
//#define LOCAL
using namespace std;

//O(n^2 * k) check for pair ?

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
int n, k;
//ll a[maxn];

//check T
void solve()
{
	cin >> n >> k; //care n = 1
	vector<vector<int>> a(k, vector<int>(n)); //store
	vector<vector<bool>> occ(n+1, vector<bool>(n+1,0)); //if ok to add(i -> j)
	vector<vector<bool>> ok(n+1, vector<bool>(n+1,0));
	//O(k*n^2) build ok
	rep(ii, 0, k)
	{
		rep(i, 0, n) cin >> a[ii][i];
		rep(i, 1, n) rep(j, 0, i) occ[a[ii][i]][a[ii][j]] = 1; //j->i is occred
	}

	//special judge
	//if(n == 1) {cout << 1 << endl << 0 << endl; return;}

	rep(i, 1, n+1) rep(j, 1, n+1)
	{
		ok[i][j] = (occ[i][j]^occ[j][i])&&(occ[i][j]);
		//cout << i << " " << j << " is " << ok[i][j] << " \n"[j==n];
	}

	set<int> ls; //the cur leaves, no further out degrees possible
	vector<int> G(n+1, 0);
	rep(i, 0, k) ls.insert(a[i][n-1]); //lasts
	repinv(t, 0, n-1) //O(n)
	{
		rep(i, 0, k) //O(k)
		{
			int x = a[i][t];
			if(ls.find(x) != ls.end()) continue;
			//G[x] = 0;
			for(auto it = ls.begin(); it != ls.end(); it++) //O(n)
			{
				int y = *it;
				if(ok[y][x])
				{
					G[x] = y;
					break;
				}
				//ls.erase(*it);
			}
		}
		rep(i, 0, k) ls.insert(a[i][t]);
	}
	set<int> hasindegree;
	rep(i, 1, n+1) if(G[i]!=0) hasindegree.insert(G[i]);
	cout << n-hasindegree.size() << endl;
	rep(i, 1, n+1) cout << G[i] << " \n"[i==n];
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


/*
1
4
2
1 2 3 4
3 2 1 4

3
4 4 4 0

1
4 3
1 2 3 4
3 4 1 2
1 3 2 4

1
6 3
5 1 2 3 4 6
5 3 4 1 2 6
6 5 1 3 2 4

/
1
6 3
1 2 3 4 5 6
3 4 1 2 5 6
1 3 2 4 6 5


*/
