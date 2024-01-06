#include <bits/stdc++.h>

using namespace std;
#define int ll;
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
//care max sum t for a policy is  10^5*10^9
int T;
const int maxn = 2e5+7;
int n;
int stk[maxn], top;
vector<int> a, t;
ll mx[maxn*8], sum[maxn]*8;

void build(int l, int r, int id){
	if(l == r) {mx[id] = t[l], sum[id] = t[l]; return;}
	int m = (l + r) / 2;
	build(l,m,id*2);
	build(m+1,r,id*2+1);
	pull(id);
}

void pull(int id)
{
  mx[id] = max(mx[id*2],mx[id*2+1]);
	sum[id] = sum[id*2] + sum[id*2+1]
}

//set u, v, to use
void setv(int x, int l,int r,int val,int id)
{
  if(l == r && l == x) { mx[id] = t[l], sum[id] = t[l]; return;}
  int m = (l + r) / 2;
  if(x <= m) setv(l,m,val,id*2);
  if(x > m) setv(m+1,r,val,id*2+1);
  pull(id);
  return;
}

pair<ll,ll> query(int l, int r, int L, int R, int id) //l r target L R range
{
	if(l <= L && R <= r) return mp(mx[id], sum[id]);
	int m = (L + R) / 2;
	pll res = mp(-1ll, 0ll);
	if(l <= m)
	{
		pll ql = query(l, r, L, m,id*2);
		res.X = max(res.X, ql.X), res.Y += ql.Y;
	}
	if(r > m)
	{
		pll qr = query(l, r, m+1, R,id*2);
		res.X = max(res.X, qr.X), res.Y += qr.Y;
	}
	return res;
}

void solve()
{
	cin >> n;
	a.resize(n); t.resize(n);
	map<int, int> cnt;
	vector<int> considers;
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> t[i];
	vector<pii> datas(n);
	rep(i, 0, n) datas[i] = mp(a[i], -t[i]);
	// 1 1 1 2 2 2 3 3 3
	// 7 6 5 4 3 2 5 5 1
	sort(all(datas));
	//sort as wanted
	rep(i, 0, n) a[i] = datas[i].X, t[i] = -datas[i].Y;
	build(0, n-1, 0);

	rep(i, 0, n)
	{
		if(!cnt.count(a[i]))
		{
			cnt[a[i]] = 1;
		}else{
			cnt[a[i]]++;
			considers.pb(a[i]);
		}
	}
	sort(all(considers));
	top = 0;
	repinv(i, 0, considers.size()) stk[top++] = considers[i];
	ll ans = 0;
	int l = lower_bound(all(a), considers[0]) - a.begin(), r;
	bool reset = 0;
	while(top)
	{
		int curval = stk[--top];
		if(reset) l = lower_bound(all(a), curval) - a.begin()
		r = upper_bound(all(a), curval) - a.begin() - 1;
		pll qlr = query(l, r, 0, n-1, 0);
		ans += qlr.Y - qlr.X;
		set(qlr.Y.id...)
		if(!cnt[curval+1].count()) //tle
	}


  return;
}


signed main()
{
  fastIO();
  cin >> T;
  //T = 1;
  while(T--) solve();
  return 0;
}
