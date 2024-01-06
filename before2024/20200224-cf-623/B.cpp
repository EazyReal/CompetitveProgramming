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
const int maxn = 1e5+7;
int n;
int a, b, p;
string str;
char s[maxn];

void solve()
{
	cin >> a >> b >> p;
	cin >> str;
	n = str.size();
	rep(i, 1, n+1) s[i] = str[i-1];
	s[0] = ' ';
	s[n] = 'C';
	//debug(n); debug(s);
	//char prev = s[n-1];
	ll sum = 0; //no use ll wa on 48(max = 1e5*1e5)
	int ans = n;
	int last = n;
	repinv(i, 1, n)//s[n-1] s[n]
	{
		//debug(i); debug(s[i]); debug(s[i+1]);
 		if(s[i] != s[i+1]) sum += ((s[i]=='A')?a:b);
		//if(i == n-1 && s[n-1] == s[n]) sum += ((s[n-1]=='A')?a:b);
		//if(i == 1 && s[1] == s[2]) sum += ((s[1]=='A')?a:b);
		if(sum <= p)
		{
			ans = i;
		}
	}
	while( ans > 1 && s[ans-1] == s[ans]) ans--;
	cout << ans << endl;
  return;
}
//concept of pay on arrival ww

signed main()
{
  fastIO();
  cin >> T;
  //T = 1;
  while(T--) solve();
  return 0;
}
