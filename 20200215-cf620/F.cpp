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

//mt19937 mrand(random_device{}());
//const ll mod=1e9+7;
//int rnd(int x) { return mrand() % x;}
//ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//INT_MAX, ULLONG_MAX, LLONG_MAX or numeric_limits<int>::min()

//------------------------------------------------------------------------//
int T;
const int maxn = 2e4+5;
int n, m, k;
int a[55][maxn];
int dp[55][maxn];
int pre[55][maxn];

inline int seg(int i1, int i2, int jl, int jr)
{
  jl--;
  return pre[i1][jr]-pre[i1][jl] + pre[i2][jr]-pre[i2][jl];
}

template<class T>
struct segment_tree
{
	int n, N;
	vector<T> a;
	vector<T> lazy;

	segment_tree(int n) : a(n*4+5, 0), lazy(n*4+5, 0), n(n), N(n*4+5) {} //remember this write way

	void push(int root)
	{
		if(lazy[root])
		{
			int lc = root<<1, rc = (root<<1)^1;
			if(lc < N) lazy[lc] += lazy[root];
			if(rc < N) lazy[rc] += lazy[root];
			a[root] += lazy[root];
			lazy[root] = 0;
		}
	}

	T pull(int root)
	{
		push(root);
		int lc = root<<1, rc = (root<<1)^1;
		if(lc > N && rc > N) return a[root];
		T &ret = a[root];
		ret = LLONG_MIN; //this should
		if(lc < N) push(lc);
		if(rc < N) push(rc);
		if(lc < N) ret = max(ret, a[lc]);
		if(rc < N) ret = max(ret, a[rc]);
		return ret;
	}

	void add(int x, int y, T val, int l, int r, int root)
	{
		if(l > r) return;
		if(x <= l && r <= y) { lazy[root] += val; return;}
		push(root);
		int M = (l+r)>>1;
		int lc = root<<1, rc = (root<<1)^1;
		if(x <= M) add(x, y, val, l, M, lc);
		if(y > M) add(x, y, val, M+1, r, rc);
		pull(root);
	}

	T query(int x, int y, int l, int r, int root)
	{
		if(l>r) return LLONG_MIN;
		push(root);
		if(x <= l && r <= y) return a[root];
		int M = (l+r)>>1;
		int lc = root<<1, rc = (root<<1)^1;
		T ret = LLONG_MIN;
		if(x <= M) ret = max(ret, query(x, y, l, M, lc));
		if(y > M) ret = max(ret, query(x, y, M+1, r, rc));
		return ret;
	}

	void print(int l, int r, int root) //for debug seg
	{
		push(root);
		cout << "Node " << root << " range is " << l << ' ' << r << " val is " << a[root]+lazy[root] << endl;
		int M = (l+r)>>1;
		int lc = root<<1, rc = (root<<1)^1;
		if(lc < N) print(l, M, lc);
		if(rc < N) print(M+1, r, rc);
	}
};

void solve()
{
  cin >> n >> m >> k;
  rep(i, 1, n+1) a[i][0] = 0, a[i][m+1] = 0;
  rep(i, 1, n+1)rep(j, 1, m+1) cin >> a[i][j], pre[i][j] = pre[i][j-1] + a[i][j];
  rep(j, 1, m+1) a[n+1][j] = 0;

  rep(j, 1, m-k+2) dp[1][j] = seg(1, 2, j, j+k-1);
  //cout << endl; rep(j, 1, m-k+2) cout << dp[1][j] << " \n"[j==m-k+1];
  rep(i, 2, n+1)
  {
    segment_tree<int> st(m);
    rep(j, 1, m-k+1+1) st.add(j, j, dp[i-1][j], 1, m, 1);
    rep(j, 1, k+1) st.add(1, j, -a[i][j], 1, m, 1);
    rep(j, 1, m-k+1+1)
    {
      dp[i][j] = st.query(1, m, 1, m, 1) + seg(i, i+1, j, j+k-1);
      if(j != m-k+1)
      {
        st.add(max(1, j-k+1), j, a[i][j], 1, m, 1);
        st.add(j+1, j+k, -a[i][j+k], 1, m, 1);
      }
    }
  }

  cout << *max_element(dp[n]+1, dp[n]+m-k+1+1) << endl;
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
