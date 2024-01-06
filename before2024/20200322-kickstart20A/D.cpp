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
int n, k;
//ll a[maxn];

namespace Trie
{
	int ans;
	struct node
	{
			int np, d;
			char key;
	    node *cs[26];
			node *p;

			node()
			{
				rep(i,0,26) cs[i] = nullptr;
				np = 0;
				p = nullptr;
				d = 0;
			}
			node(node* _p, char _cc, int _np, int _dep)
			{
				rep(i,0,26) cs[i] = nullptr;
				np = 0;
				p = _p;
				key = _cc;
				np = _np;
				d = _dep;
			}
	};

	void insert(node* o, char* c)
	{
		node *cur = o;
		//cur->np++;
		while(*c)
		{
			//debug(*c);
			if(cur->cs[*c-'A'] == nullptr) cur->cs[*c-'A'] = new node(cur, *c, 0, cur->d+1);
			cur = cur->cs[*c-'A'];
			//cur->np++;
			c++;
		}
		cur->np++;
	}

	void print(node *o)
	{
		debug(o->key); debug(o->np); debug(o->d);
		rep(i, 0, 26) if(o->cs[i] != nullptr) print(o->cs[i]);
	}

	void deletee(node *o)
	{
		rep(i, 0, 26) if(o->cs[i] != nullptr) deletee(o->cs[i]);
		delete o;
	}

	void mergee(node *o)
	{
		rep(i, 0, 26) if(o->cs[i] != nullptr) mergee(o->cs[i]);
		/*if(o->np == k)
		{
			ans += o->d;
			return;
		}*/
		//debug(ans);
		ans += (o->np/k) * o->d;
		if(o->p == nullptr) return;
		o->p->np += o->np%k;
		return;
	}
}

using namespace Trie;

//check T
void solve(int tc)
{
	cin >> n >> k;
	vector<string> ss(n);
	rep(i, 0, n) cin >> ss[i];
	//sort(all(ss));
	/*rep(i, 0, n)
	{
		while(ss[i])
	}*/
	//cout << "test trie : " << trie_search(root, "RAINBOW") << endl;
	node* rt = new node(nullptr, '#', 0, 0);
	rep(i, 0, n) Trie::insert(rt, strdup(ss[i].c_str()));
	//print(rt);
	ans = 0;
	mergee(rt);
	deletee(rt);
	cout << "Case #" << tc << ": " << ans << endl;
  return;
}


signed main()
{
  fastIO();
  T = 1;
  cin >> T; //this
  rep(i, 1, T+1) solve(i);
  return 0;
}
