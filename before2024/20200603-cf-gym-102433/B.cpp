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
int a[maxn];

//check T
void solve()
{
  //cin >> n; rep(i, 0, n) cin >> a[i];
  cin >> n >> k;
  rep(i, 0, n) cin >> a[i];
  vector<int> vis(k+1, -1);
  vector<bool> last(n, 0);
  repinv(i, 0, n)
  {
    if(vis[a[i]] == -1)
    {
      vis[a[i]] = i;
      last[i] = 1;
    }
  }
  int idx = 0;
  int deleteid = 0;
  int lastv = -1;
  vector<int> vis2(k+1, 0);
  vector<int> ans;
  set<pii> s;
  while(idx < n)
  {
    while(!last[idx] && idx < n)
    {
      if(!vis2[a[idx]]) s.insert({a[idx], idx});
      idx++;
    }
    if(idx < n) // insert lastv 
    {
      if(!vis2[a[idx]]) s.insert({a[idx], idx});
      lastv = a[idx];
      idx++;
    }
    while(s.size())
    {
      pii bst = *s.begin();
      s.erase(bst);
      if(!vis2[bst.X])
      {
        ans.pb(bst.X);
        vis2[bst.X] = 1;
        last[vis[bst.X]] = 0; //remove last of that number
        for(int i = deleteid; i <= bst.Y; i++) s.erase({a[i], i});
        deleteid = bst.Y+1; 
      }
      if(bst.X == lastv) //remove the cur last adding new candidate
      {
        break;
      }
    }
  }
  assert(ans.size() == k);
  rep(i, 0, ans.size()) cout << ans[i] << " \n"[i==ans.size()-1];
  return;
}


//g++ -o out -std=c++11 A.cpp

signed main()
{
  fastIO();
  T = 1;
  //cin >> T; //this
  rep(tc, 1, T+1)
  {
    //cout << "Case #" << tc << ": ";
    solve();
  }
  return 0;
}

/*
25 13
1 3 4 6 7 9 8 10 5 2 11 13 12 9 7 6 4 3 1 8 5 2 9 7 6 4

*/