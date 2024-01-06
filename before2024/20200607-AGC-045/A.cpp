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
#define int ll
int T;
const int maxn = 200+7;
int n;
ll a[maxn];
string S;

//for vector space
const int d = 61; //max bit at <=60
int basis[d]; // basis[i] keeps the mask of the vector whose f value is i
int rankk; // Current size of the basis
int rankk2;

int basis2[d];

//class VectorSpace

void insertv(int v) {
	rep(i, 0, d)
  {
		if((v & 1 << i) == 0) continue; // continue if i != f
		if(!basis[i]) ///there is no basis for f
    { 
			basis[i] = v;
			++rankk;
			return;
		}
		v ^= basis[i]; // remove the f part
	}
}

/*
void insert_remove(int v) {
	rep(i, 0, d)
  {
		if((v & 1 << i) == 0) continue; // continue if i != f
		if(!basis2[i]) ///there is no basis for f
    { 
			basis2[i] = v;
			++rankk2;
			return;
		}
		v ^= basis2[i]; // remove the f part
	}
}
*/

void removev(int v) {
  vector<int> new_basis;
  set<int> tmp;
	rep(i, 0, d)if(basis[i])
  {
    int c1 = basis[i];
    int c2 = basis[i]^v;
    if(tmp.find(c1) != tmp.end() || tmp.find(c2) != tmp.end()) continue;
    else{
      new_basis.pb(basis[i]);
      tmp.insert(basis[i]);
    }
	}
  memset(basis, 0, sizeof(basis));
  rankk = 0;
  for(int b : new_basis)
  {
    debug(b);
    insertv(b);
  }
  debug(rankk);
  return;
}

//check T
void solve()
{
  cin >> n;
  rep(i, 0, n) cin >> a[i];
  cin >> S;

  memset(basis, 0, sizeof(basis));
  rankk = 0;

  rep(i, 0, n)
  {
    if(S[i] == '0')
    {
      removev(a[i]);
      //debug(rankk);
      //rep(di, 0, 3) {debug(di); debug(basis[di]);}
    }
    else{
      insertv(a[i]);
      //debug(rankk);
      //rep(di, 0, 3) {debug(di); debug(basis[di]);}
    }
  }
  //debug(rankk);
  cout << (rankk != 0) << endl;

  return;
}


//g++ -o out -std=c++11 A.cpp

signed main()
{
  fastIO();
  T = 1;
  cin >> T; //this
  rep(tc, 1, T+1)
  {
    //cout << "Case #" << tc << ": ";
    solve();
  }
  return 0;
}

/*

4
1 4 3 6
1100

4
1 4 4 1
1100

3
2
1 2
10
2
1 1
10
6
2 3 4 5 6 7
111000

1
6   
2 3 4 7 6 5
111000

1
6   
2 3 4 7 5 6
111000

1
6
1 2 4 5 7 6
111000

*/