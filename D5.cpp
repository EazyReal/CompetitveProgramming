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
//care max sum t for a policy is  10^5*10^9

//this is almost same as my segment tree solution
//why didn't i consider setv(0) as pop in priority queue :(

void solve()
{
	cin >> n;
	vector<pll> a(n);
	for(pll &ai : a) cin >> ai.X;
	for(pll &ai : a) cin >> ai.Y;
	sort(all(a));
	//rep(i, 0, n) cout << a[i].X << ' ' << a[i].Y << '\n';
	ll ans = 0;
	ll sum = 0;
	ll curv;
	priority_queue<ll> pq;
	rep(i, 0, n)
	{
		curv = a[i].X;
		pq.push(a[i].Y);
		sum += a[i].Y;
		while((i == n-1 || curv != a[i+1].X) && !pq.empty()) //if nxt is same consider nxt
		{
			//debug(pq.top());
			sum -= pq.top(); pq.pop(); //expecpt max all +1
			ans += sum;
			curv++;
			//debug(curv);
		}
	}
	cout << ans << endl;

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
