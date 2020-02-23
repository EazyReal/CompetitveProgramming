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
int T;
const int maxn = 2e5+7;
int n;
int stk[maxn], top;
//care max sum t for a policy is  10^5*10^9

long long seg[maxn*8],mx[maxn*8],a[maxn],p[maxn];
int u,v;
void pull(int id)
{
  mx[id] = max(mx[id*2],mx[id*2+1]) + seg[id];
}
void push(int id)
{
  seg[id*2] += seg[id];
  seg[id*2+1] += seg[id];
  seg[id] = 0;
  pull(id*2);
  pull(id*2+1);
  pull(id);
}

//set u, v, to use
void add(int l,int r,int val,int id)
{
  if(u <= l && r <= v)
  {
    seg[id] += val;
    pull(id);
    return;
  }
  push(id);
  int m = (l + r) / 2;
  if(u <= m) add(l,m,val,id*2);
  if(v > m) add(m+1,r,val,id*2+1);
  pull(id);
  return;
}

void solve()
{
	cin >> n;
	vector<int> a(n), t(n);
	map<int, int> maxcost;
	map<int, int> cnt;
	map<int, int> sumcost;
	vector<int> considers;
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> t[i];
	rep(i, 0, n)
	{
		if(!cnt.count(a[i]))
		{
			cnt[a[i]] = 1;
			maxcost[a[i]] = t[i];
			sumcost[a[i]] = t[i];
			//considers.pb(a[i]);
		}else{
			cnt[a[i]]++;
			considers.pb(a[i]);
			maxcost[a[i]] = max(maxcost[a[i]], t[i]);
			sumcost[a[i]] += t[i];
		}
	}
	sort(all(considers));
	top = 0;
	repinv(i, 0, considers.size()) stk[top++] = considers[i];
	ll ans = 0;
	while(top)
	{
		int curval = stk[--top];
		if(cnt[curval] > 1)
		{
			ans += sumcost[curval] - maxcost[curval];
			if(!cnt[curval+1].count()) //tle
		}
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
