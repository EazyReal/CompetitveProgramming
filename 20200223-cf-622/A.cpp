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
int a[5];

//ob max: 2^3-1 = 7 0/1 0/1 0/1

void solve()
{
	cin >> a[0] >> a[1] >> a[2];
	rep(i, 0, 3) a[i] = min(a[i], 3);
	sort(a, a+3);
	int cnt0 = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
	rep(i, 0, 3) cnt0 += (a[i] == 0);
	rep(i, 0, 3) cnt1 += (a[i] == 1);
	rep(i, 0, 3) cnt2 += (a[i] == 2);
	rep(i, 0, 3) cnt3 += (a[i] == 3);
	if(cnt0 == 3)
	{
		cout << 0 << endl;
	}else if(cnt0 == 2)
	{
		cout << 1 << endl;
	}else if(cnt0 == 1)
	{
		if(a[1] == 1 && a[2] == 1) cout << 2 << endl;
		else if(a[1] == 1 && a[2] == 2) cout << 2 << endl;
		else if(a[1] == 2 && a[2] == 2) cout << 3 << endl;
		else cout << 3 << endl;
	}else if(cnt0 == 0)
	{
		if(cnt1 >= 2) cout << 3 << endl; //1 1 1 1 1 2
		else if(cnt1 == 1) cout << 4 << endl; // 1 2 2 1 2 3
		else if(cnt2 == 3) cout << 4 << endl;//2 2 2
		else if(cnt2 + cnt3 == 3 && cnt2 && cnt3) cout << 5 <<endl;
		else if(cnt3 == 3) cout << 7 <<endl;
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
