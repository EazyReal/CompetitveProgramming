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

//------------------------------------------------------------------------//
int T;
const int maxn = 3e5+7;
int n;
int p[maxn], q[maxn], id[maxn];

//[l,r)
template<class T>
struct simple_seg
{
	int n, N;
	vector<T> vals;
	vector<T> lazy;
	simple_seg<T>(int n, T init_val) : n(n), N(4*n+100), vals(N, init_val), lazy(N, init_val) {};

#define m (l+r>>1)
#define lc (o<<1)
#define rc (o<<1|1)
#define lcc l, m, lc
#define rcc m, r, rc

	T f(T u, T v)
	{
		return min(u, v);
	}

	void push(int o)
	{
		if(lazy[o])
		{
			lazy[lc] += lazy[o];
			lazy[rc] += lazy[o];
			vals[o] += lazy[o];
			lazy[o] = 0;
		}
	}

	T getv(int o) {return o <= N ? vals[o] + lazy[o] : INT_MAX;}

	void pull(int o)
	{
		vals[o] = f(getv(lc),getv(rc));
	} 

	void build(int l, int r, int o)
	{
		if(r <= l) return;
		if(r-l == 1) {vals[o] = 0; return;} //init code
		//int m = l+r >> 1; //2, 3 => 2, 2,2, 2,3 => infinity loop
		build(lcc);
		build(rcc);
		
		pull(o);
	}

	void add(int L , int R, T addv, int l, int r, int o)
	{
		if(r <= l) return;
		if(L >= r || R <= l) return;
		if(L <= l && r <= R) {lazy[o] += addv; return; }
		push(o);
		add(L, R, addv, lcc);
		add(L, R, addv, rcc);
		pull(o);
		return;
	}

	T query(int L , int R, int l, int r, int o)
	{
		if(r <= l) return INT_MAX;
		if(L >= r || R <= l) return INT_MAX; //should no effect value, min of int => INT_MAX
		if(l <= L && R <= r) {return getv(o);} //typo, wrong direction
		push(o);
		//f(query(L, R, addv, lcc), query(L, R, addv, rcc));
		return f(query(L, R, lcc), query(L, R, rcc));;
	}

	void print(int l, int r , int o )
	{
		if(r <= l) return;
		cout << "Node " << o << ", l = " << l << ", r = " << r << "vals" << vals[o] << "lazy" << lazy[o] << endl;
		if(r-l == 1) return;
		print(lcc);
		print(rcc);
	}

};

void solve()
{
	cin >> n;
	rep(i, 1, n+1) cin >> p[i], id[p[i]] = i;
	rep(i, 1, n+1) cin >> q[i];
	simple_seg<int> seg(n+5, 0);
	int cur = n;
	//seg.print(1, n+1, 1);
	seg.add(1, 3, 4, 1, n+1, 1);
	seg.add(3, n+1, 5, 1, n+1, 1);
	//debug(seg.getv(1));
	//seg.print(1, n+1, 1);
	seg.add(1, 3, -4, 1, n+1, 1);
	seg.add(3, n+1, -5, 1, n+1, 1);
	rep(i, 1, n+1)
	{
		while(1) 
		{
			seg.add(1, id[cur--]+1, -1, 1, n+1, 1); //add requisition
			//debug(seg.getv(1));
			if(seg.getv(1) < 0)
			{
				//debug(cur+1);
				seg.add(1, id[++cur]+1, 1, 1, n+1, 1); //not match => back off
				break;
			}
		}
		//cout << "?";
		//cout << seg.query(1, n+1, 1, n+1, 1) << endl;
		cout << cur << " \n"[i==n];
		seg.add(1, q[i]+1, 1, 1, n+1, 1); //add supply
	}
	return ;
};

signed main()
{
  fastIO();
  T = 1;
  //cin >> T; //this
  while(T--) solve();
  return 0;
}

/*
6
2 3 6 1 5 4
5 2 1 4 6 3
*/