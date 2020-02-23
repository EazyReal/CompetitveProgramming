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
int n, m;

const int maxn = 4000+5;
const int maxm = 4000+5;

vector<int> G[maxn];
bool p[maxn]; //p[2*i] = pi true, p[2*i+1] = pi false
int stk[maxn], top;

inline int id(int x) {return 2*(abs(x)-1) + (x<0);}

bool dfs(int u) //u is id
{
	if(p[u^1]) return 0;
	if(p[u]) return 1;
	stk[top++] = u;
	p[u] = 1;
	for(auto& v: G[u])
	{
		if(!dfs(v)) return 0;
	}
	return 1;
}

bool sat()
{
	memset(p, 0, sizeof p);
	rep(i, 1, n+1)
	{
		if(!p[id(i)] && !p[id(-i)])
		{
			top = 0;
			if(!dfs(id(i)))
			{
				while(top) p[stk[--top]] = 0; //reset
				if(!dfs(id(-i)))
				{
					//while(top) p[stk[--top]] = 0;
					//debug(i);
					return 0;
				}
			}
		}
	}
	return 1;
}


void solve()
{
	//auto tf = [&](int x) return x<0;
	//auto id = [&](int x) return 2*(abs(x)-1)+tf(x);

	cin >> n >> m;
	int a, b;
	bool hasnn = 0;
	rep(i, 0, m)
	{
		cin >> a >> b;
		//debug(id(a)); debug(id(b));
		hasnn |= a < 0 && b < 0;
		G[id(-a)].pb(id(b));
		G[id(-b)].pb(id(a));
	}
	if(!sat()) cout << 0 << endl; //no solution aleady
	else if(!hasnn) cout << -1 << endl;  //no ~x is sure
	//else if(!satf1()) cout << 1 << endl; //a certain x
	else{
		rep(x, 1, n+1)
		{
			G[id(-x)].pb(id(x)); //force x to be choosen
			if(!sat())
			{
				cout << 1 << endl;
				return ;
			}
			G[id(-x)].pop_back();
		}
		cout << 2 << endl; //x∨x y∨y for any ~x∨~y
	}
	//x > 0
	return ;
}


signed main()
{
  //fastIO();
  //cin >> T;
  T = 1;
  while(T--) solve();
  return 0;
}

/*
3 2
1 2
-1 -2
should be 2
3
3
1 2
-1 -2
3 3
2

3 4
1 2 2 1 -1 2 -2 1
0 
*/
