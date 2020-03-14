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

//check T
//obs : worst = a+b+c concat

int matches(string a, string b, int x, int y) //from x and from y the max l ok
{
	int i = 0;
	while(x+i < a.size() && y+i < b.size() && (a[x+i] == b[y+i] || a[x+i] == '?' || b[y+i] == '?') )
	{
		i++;
	}
	return i; //length of eq
}
//3! first deter order

//bool cmp(string &a, string &b){ return a.size()<b.size()};

string mergee(string a1, string a2)
{
	string b12 = a1+a2;
	rep(i, 0, a1.size())a
	{
		int r = matches(a1, a2, i, 0);
		if( !(r == a1.size()-i  || r >= a2.size())) continue; //check for ok to end
		//debug(r);
		string a12;
		rep(k, 0, i) a12.pb(a1[k]);
		rep(k, 0, r)
		{
			if(a1[i+k] == '?' && a2[k]=='?')a12.pb('?');
			else if(a1[i+k] == '?') a12.pb(a2[k]);
			else if(a2[k] == '?') a12.pb(a1[i+k]);
			else a12.pb(a1[i+k]);
		}
		if(r == a1.size()-i) rep(k, r, a2.size()) a12.pb(a2[k]);
		else rep(k, i+r, a1.size()) a12.pb(a1[k]);
		//debug(a12);
		if(a12.size() < b12.size()) b12 = a12;
	}
	return b12;
}

void solve()
{
	string a[3];
	cin >> a[0] >> a[1] >> a[2];
	//sort(all(a), cmp);

	int per[] = {0, 1, 2};
	string best = a[0] + a[1] + a[2];
	do {
		string a1 = a[per[0]];
		string a2 = a[per[1]];
		string a3 = a[per[2]];

		string b12 = mergee(a1, a2);
		//debug(a1); debug(a2); debug(b12);
		string b123 = mergee(b12, a3);
		if(b123.size() < best.size()) best = b123;
		//b12 is best of 12
		//debug(b123);
	} while ( std::next_permutation(per,per+3) );
	cout << best.size() << endl;
	//debug(best);
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
??? aaa bbb 6
?aa b?? aab 4
abcd bc cde 5
*/
