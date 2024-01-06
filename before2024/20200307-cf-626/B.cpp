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
const int maxn = 4e4+7;
int n, m, k;
int a[maxn];
int b[maxn];
int cnt[2][maxn];

//check T
void solve()
{
	cin >> n >> m >> k;
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, m) cin >> b[i];

	memset(cnt[0], 0, sizeof(cnt[0]));
	memset(cnt[1], 0, sizeof(cnt[1]));

	int cur = 0;
	int ma = 0, mb = 0;
	//a
	rep(idx, 0, n)
	{
		if(a[idx] == 0)
		{
			/*
			rep(i, 1, cur+1)
			{
				cnt[0][i] += cur-i+1;
			}
			*/
			cnt[0][cur]++;
			ma = max(ma, cur);
			cur = 0;
		}else{
			cur++;
		}
	}
	cnt[0][cur]++;
	ma = max(ma, cur);
	//b
	cur = 0;
	rep(idx, 0, m)
	{
		if(b[idx] == 0)
		{
			/*
			rep(i, 1, cur+1)
			{
				cnt[0][i] += cur-i+1;
			}
			*/
			cnt[1][cur]++;
			mb = max(mb, cur);
			cur = 0;
		}else{
			cur++;
		}
	}
	//debug(cur);
	cnt[1][cur]++;
	mb = max(mb, cur);

/*
	rep(ii, 0, 2)
	{
		cout << ii << endl;
		rep(i, 1, max(n,m)+1) cout << i << " " << cnt[ii][i] << " \n"[i==max(n,m)];
		cout << endl;
	}
*/
	/*repinv(i, 1, n)
	{
		cnt[0][i] += cnt[0][i+1]*2;
	}
	rep(i, 1, m)
	{
		cnt[0][i] += cnt[0][i+1]*2;
	}*/
	std::vector<int> ca, cb;//candi
	rep(i, 1, n+1) if(cnt[0][i]) ca.pb(i);
	rep(i, 1, m+1) if(cnt[1][i]) cb.pb(i);

	vector<int> facs;
	bool flag = 0;
	for(int i = 1; i*i <= k; i++) if(k%i==0)
	{
		facs.pb(i);
		if(i*i!=k) facs.pb(k/i);
	}
	//rep(i, 0, facs.size()) debug(facs[i]);

	ll ans = 0;
	rep(i, 0, facs.size())
	{
		int a = facs[i];
		int b = k/facs[i];
		//debug(cnt[0][facs[i]]*cnt[1][k/facs[i]]);
		//ans += cnt[0][facs[i]]*cnt[1][k/facs[i]];
		ll aw = 0, bw = 0;
		//rep(j, a, ma+1) aw += cnt[0][j]*(j-a+1) ;
		//rep(j, b, mb+1) bw += cnt[1][j]*(j-b+1) ;
		for(int x : ca)if(x>=a) aw += cnt[0][x]*(x-a+1) ;
		for(int x : cb)if(x>=b) bw += cnt[1][x]*(x-b+1) ;
		ans += aw*bw;
	}

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
3
3
4
1
1
0
1
1
1
*/
