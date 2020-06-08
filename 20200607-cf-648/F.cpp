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

template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
    out << "[";
    size_t last = v.size() - 1;
    for (size_t i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i != last)
            out << ", ";
    }
    out << "]";
    return out;
}

int T;
const int maxn = 500+7;
int n;
vector<int> a;
vector<int> b;

/*
void dfs(vi u, int d)
{
  if(d == 0) return;
  cout << u << endl;
  rep(i, 1, n/2+1) //n to swap
  {
    rep(j, 0, i) swap(u[j], u[n-i+j]); //swap
    dfs(u, d-1);
    rep(j, 0, i) swap(u[j], u[n-i+j]);
  }
}
*/

//check T
void solve()
{
  cin >> n;
  a.resize(n);
  b.resize(n);
  multiset<int> sa;
  multiset<int> sb;
  rep(i, 0, n) cin >> a[i], sa.insert(a[i]);
  rep(i, 0, n) cin >> b[i], sb.insert(b[i]);
  //dfs(a, 3);
  auto ita = sa.begin();
  auto itb = sb.begin();

  bool same = 1;
  while(ita != sa.end())
  {
    if(itb == sb.end()) {same = 0; break;}
    if(*ita != *itb) {same = 0; break;}
    ita++;
    itb++;
  }
  bool ok = same;
  if(n%2 == 1) ok &= (a[n/2] == b[n/2]);
  cout << ( ok ? "Yes" : "No") << endl; 

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
