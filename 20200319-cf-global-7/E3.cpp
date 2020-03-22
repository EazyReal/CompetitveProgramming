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
const int maxn = 3e5+7;
int n;
ll p[maxn], q[maxn];

pii operator+(pii a, pii b)
{
	return mp(a.X+b.X, a.Y+b.Y);
}

void operator+=(pii &a, pii &b)
{
	a.X += b.X; a.Y += b.Y;
}

template<class T>
struct segment_tree
{
	/*
	 adrui's Segment Tree
	*/

	//無區間合併的區間更新 & 查詢
	const int N = 300000 + 5;

	int ans[N << 2], lazy[N << 2];                          //陣列， 不需要區間合併的時候陣列可以

	#define mid ((l + r) >> 1)
	#define ls  rt << 1, l, mid
	#define rs  rt << 1 | 1, mid + 1, r                     //區間巨集

	void pushUp(int rt) {//向上更新
	    //code
			ans[rt] = min(ans[ls], ans[rs]) 
	}

	void down(int s, int f){
	    //lazy下移
	}
	void pushDown(int rt) {
	    if(lazy[rt]){
	        down(rt << 1, rt);//lson
	        down(rt << 1 | 1, rt);//rson
	        lazy[rt] = 0;
	    }
	}

	void build(int rt, int l, int r) {
	    if (l == r) {
	        //init
	        return;
	    }

	    build(ls);//lson
	    build(rs);//rson

	    pushUp(rt);//更新父節點
	}

	void update(int rt, int l, int r, int L, int R, int v) {//區間更新（單點的就不講了）
	    if (L <= l && R >= r) {
	        //update
	        ans[rt] += v;
	        lazy[rt] = 1;
	        return;
	    }

	    pushDown(rt);

	    if(L <= mid) update(ls, L, R, v);//lson更新
	    if (R > mid)    update(rs, L, R, v);//rson更新

	    pushUp(rt);
	}

	int query(int rt, int l, int r, int L, int R) {//查詢的是直接的值（以區間求和為例）

	    if (L <= l && R >= r) {
	        return ans[rt];
	    }

	    //pushDown(rt);lazy下移（有lazy時不能省）

	    int res = 0;

	    if (L <= mid)  res += query(ls, L, R);//lson查詢
	    if (R > mid) res += query(rs, L, R);//rson查詢

	    return res;
	}
};


//check T
void solve()
{
	cin >> n;
	rep(i, 0, n) cin >> p[i];
	rep(i, 0, n) cin >> q[i];
	//cout << n << ' ';
	vector<int> ans;
	segment_tree<pii> st(n+5);
	rep(i, 1, n+1) st.add(i, i, mp(p[i-1], i), 1, n, 1); //nlogn build
	int curmax = -1;
	repinv(i, 1, n)
	{
		int cur = q[i];
		pii foundmin = st.query(cur, n, 1, n, 1);
		curmax = max(curmax, foundmin.X);
		st.add(foundmin.Y, foundmin.Y, mp(100000000, 0), 1, n, 1);
		ans.pb(curmax);
		//debug(curmax);
	}
	cout << n << ' ';
	repinv(i, 0, n-1) cout << ans[i] << " \n"[i==n];
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
