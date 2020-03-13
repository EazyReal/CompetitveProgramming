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
//ll a[maxn];
#define SZ(x) tt[x].size()
//check T
void solve()
{
	cin >> n;
	vector<string> ss(n);

	map<string, int> cnt; //use the lexically smaller one ; no
	vector<int> tt[4];
	int ht[2][2] = {{0, 0}, {0, 0}};
	bool flag = 0;//no sol

	int pre = 0;
	vector<int > ans;

	rep(i, 0, n)
	{
		cin >> ss[i];
		int nn = ss[i].size();
		string srev = ss[i];
		reverse(all(srev));
		int c1 = cnt[ss[i]];
		int c2 = cnt[srev];
		int cc = c1+c2;
		if(cc > 1) flag = 1; //if rev same will do
		if(c1 == 0)
		{
			cnt[ss[i]]++;
		}else{
			cnt[srev]++;
			ss[i] = srev;
			pre++;
			ans.pb(i);
		}
		//ht[0][ss[i][0]]++;
		//ht[1][ss[i][nn-1]]++;
		//if(ss[i][0] == 0 && )
		int h = ss[i][0]-'0', t = ss[i][nn-1]-'0';
		tt[h*2+t].pb(i);
	}

	if(tt[0].size() && tt[3].size() && ((tt[1].size()+tt[2].size()) == 0)) flag = 1;
	if(flag) {cout << -1 << endl; return;}
	//try to get to 01 10 difference == 1 or 0 id SZ(0) && SZ(3)
	int ok = 0;
	auto& a = (tt[1].size() > tt[2].size()) ? tt[1] : tt[2];
	auto& b = (tt[1].size() > tt[2].size()) ? tt[2] : tt[1];
	int target = (a.size()-b.size())/2;
	//debug(target);
	rep(i, 0, a.size())
	{
		string srev = ss[a[i]];
		reverse(all(srev));
		if(cnt[srev] == 0) ok++, ans.pb(a[i]);
	}
	if(ok >= target)
	{
		int all = pre+target;
		cout << all << endl;
		rep(i, 0, all) cout << ans[i]+1 << " \n"[i==all-1];
	}else{
		cout << -1 << endl;
	}

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
