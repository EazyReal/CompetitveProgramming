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

//------------------------------------------------------------------------//
int T;
const int maxn = 5000+5;
int n, m;

vector<int> s;
vector<int> cows[maxn];

void solve()
{
  cin >> n >> m;
  s.resize(n+1);
  s[0] = 0;
  rep(i, 1, n+1) cin >> s[i];//s[i+1] bug for more than 30 min
  int fi, hi;
  rep(i, 0, m)
  {
    cin >> fi >> hi;
    cows[fi].pb(hi);
  }
  rep(i, 1, n+1) sort(all(cows[i]));

  int maxv = 0;
  ll ans = 0;
  rep(i, 0, n+1)//mid point
  {
    //bug : pre(n, 0) for 30 min
    vector<int> pre(n+1, 0); //prefix sum O(n2)ok
    vector<int> suf(n+1, 0); //suffux sum
    rep(c, 1, i+1) pre[s[c]]++; //including cur
    rep(c, i+1, n+1) suf[s[c]]++;

    //determine the cut point is ok or no cut point (all  right)
    bool okl = i==0;
    for(auto& cowi: cows[s[i]]) if(cowi == pre[s[i]]) okl = 1;
    if(!okl) continue;

    ll curway = 1ll;
    int curn = 0;

    //deal with cut point's color
    if(i != 0)
    {
      int c = s[i];
      int y = upper_bound(all(cows[c]), suf[c]) - cows[c].begin();
      if(pre[c] <= suf[c]) y--; //cant use the cut point's cow
      if(y == 0) curn = 1, curway = 1ll; //only middle
      else curn = 2, curway = ll(y); //2s
    }

    rep(c, 1, n+1) if(s[i] != c) //for each color except for cut point
    {
      int x, y;
      x = upper_bound(all(cows[c]), pre[c]) - cows[c].begin();//how many can put left of i
      y = upper_bound(all(cows[c]), suf[c]) - cows[c].begin();//how many can put right of i

      if(!x && !y) continue; //x = y = 0 => no cow added
      if(x > y) swap(x, y); // x < y
      if(!x) curway = curway*y%mod, curn++; //x==0 => only add one
      else if(y > 1) curway = curway*x*(y-1)%mod, curn+=2; // x>0, y>1 , pick one for x the pick one for y (y>x => picked x removed from y choice)
      else if(x == y && y == 1) curway = curway*2%mod, curn++; //x=1,y=1, 2way(queue in l or r)
    }
    //ebug(i); debug(curn); debug(curway);

    if(curn == maxv) ans = (ans + curway)%mod;
    else if(curn > maxv) ans = curway, maxv = curn;
  }
  cout << maxv << ' ' << ans << endl;
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
