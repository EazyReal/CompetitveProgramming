---

title: Atcoder DP Educational Contest W Intervals
tags: CPsite, CPsite-report, dp, hard, interval, datastructure
author : maxwill lin, yan-tong lin
description :  Atcoder DP Educational Contest W Intervals
updatetime : "2020/3/3 13:42"

---

# Atcoder DP Educational Contest W Intervals

## Link

* https://atcoder.jp/contests/dp/tasks/dp_w

## Tags

* dp, hard, interval, datastructure

## Solution Sketch

* solution 1:
    * build $dp[i]$ from $dp[j\in [0,i)]$
    * ignore future(not ended segment) and add back contribution 
    * smarter and informal way
    * may be harder to think of

* solution 2:
    * build $dp[i]$ from $dp[j\in [0,i)]$
    * for every interval, there are cases for relationship of interval and $i, j$
        * case 0: $i$ is before the interval => inrelevant
        * case 1: $i$ is on the interval and $j$ is before current interval => add back  current interval score
        * case 2: $i$ is on the interval and $j$ is in current interval => no add back
        * case 3: $i$ is after the interval
        * ...
    * how to count it for every interval correctly and fast
    * Anseer : **treat as l events and r events**


## Lessons Learned

* from scratch implementation of segment tree template without reference
* memory usage of segment tree
    * $MEM(n) = n+\frac{n}{2}+\frac{n}{4}...$ as  $n\in\{ 2^i \mid i \in N\}$
    * for $n\notin\{ 2^i \mid i \in N\}$ , round up n to power of 2
    * at most $4*n$ size of memory required
* interval thinking
    * as event
    * as contribution

## Other



## Verdict
![](https://i.imgur.com/ulooVHs.png)

```
2020-03-03 12:25:43	W - Intervals	dpzero 	C++14 (GCC 5.4.1)	100	4769 Byte		274 ms	25216 KB	Detail
2020-03-03 02:00:07	W - Intervals	dpzero 	C++14 (GCC 5.4.1)	100	4586 Byte		270 ms	25216 KB	Detail
```
## Code

### Solution #1
```cpp
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
ll ls[maxn];
vector<pair<ll, int>> rs[maxn];

//I think can do compression if n is 1e9, m is 1e5 (by unique and reassigning li, ri)

//T should be comparable and have +=, judge nullity
//modify LL min to wanted min
//RE , segment_tree size calc => 2pow ->*2, not 2pow->*4
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


int n, m;

void solve()
{
	cin >> n >> m;
	ll li, ri, si;
	memset(ls, 0, sizeof(ls));
	rep(i, 0, m)
	{
		cin >> li >>  ri >> si;
		ls[li] += si;
		rs[ri].pb(mp(si, li));
	}
	//build(0, n); no need, all 0ll
	segment_tree<ll> seg(n);
	ll ans = 0; //min ans = 0;
	//dpi means the best (when take the point) ignoring not ended intervals
	//after complete dpi dosen't ingnore any interval and is added only once by each intrval
	//use current to update past dp
	rep(i, 1, n+1)
	{
		ll dpi = max(0ll, seg.query(1, max(1, i-1), 1, n, 1));
		seg.add(i, i, dpi, 1, n, 1); //is set
		for(pair<ll, int>& ri : rs[i]) seg.add(ri.Y, i, ri.X, 1, n, 1);
	}
	//seg.print(1, n, 1);
	ans = max(ans, seg.query(1, n, 1, n, 1));
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
/*
stuck:
	* do observations and see properties
	* binary search? DP? DS? flow?
	* be organized

before upload:
	* int overflow, array bounds
	* special cases (min, max, special)
*/

```

### Solution #2
```cpp
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
ll ls[maxn];
vector<pair<ll, int> > rs[maxn];

//I think can do compression if n is 1e9, m is 1e5 (by unique and reassigning li, ri)

//T should be comparable and have +=, judge nullity
//modify LL min to wanted min
//RE , segment_tree size calc => 2pow ->*2, not 2pow->*4
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


int n, m;

void solve()
{
	cin >> n >> m;
	ll li, ri, si;
	memset(ls, 0, sizeof(ls));
	rep(i, 0, m)
	{
		cin >> li >>  ri >> si;
		ls[li] += si;
		rs[ri].pb(mp(si, li));
	}
	//build(0, n); no need, all 0ll
	segment_tree<ll> seg(n);
	ll ans = 0; //min ans = 0;
	//here use interval [0, i) = decide val of i, use past to decide current dp
	//if encounter l, all dpi before l need to add l(the current choice is new)
	//if encounter r, remove all contribution(the current choice no loger add ai)
	rep(i, 1, n+1) //here 0 is imaginary point means before all seg
	{
		if(ls[i] != 0) seg.add(0, i-1, ls[i], 0, n, 1); //cur and future choice is not new
		//>0 bug!!!! ls[i] is not >0 sometimes, debug by print seg
		ll dpi = seg.query(0, i-1, 0, n, 1);
		ans = max(ans, dpi);
		//debug(ans);
		//seg.print(0, n, 1);
		seg.add(i, i, dpi, 0, n, 1); //cur pos best with cur pos 1 is
		for(pair<ll, int> ri : rs[i]) seg.add(0, ri.Y-1, -ri.X, 0, n, 1); //for over r there is no need to add for before val
	}
	//seg.print(0, n, 1);
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
/*
stuck:
	* do observations and see properties
	* binary search? DP? DS? flow?
	* be organized

before upload:
	* int overflow, array bounds
	* special cases (min, max, special)
*/

```