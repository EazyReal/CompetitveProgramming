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

//mt19937 mrand(random_device{}());
const ll mod=1e9+7;
//int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//INT_MAX, ULLONG_MAX, LLONG_MAX or numeric_limits<int>::min()

//------------------------------------------------------------------------//
#define int ll
//WA 1 max ans is 1e5^2 
int T;
int n;

//obervation have 3 -> have 2(and position fixed) => 2 always better
//care : aaaaaaaa aa aaa? ok
//reduce tio find max pair a, b

//complexity 26*26*n?

int cnt[27];
const int maxn = 1e5+10;
//int dp[maxn];

void solve()
{
  string s;
  cin >> s;
  n = s.size();
  MEM(cnt, 0);
  int ans = -1;
  rep(i, 0, n)
  {
    cnt[s[i]-'a']++;
    ans = max(ans, cnt[s[i]-'a']);
  }
  rep(i, 0, 26)rep(j, 0, 26)if(cnt[i] && cnt[j])
  {
    int sum = 0;
    int prei = 0;
    rep(k, 0, n)
    {
      if(s[k] == 'a'+j) sum+= prei; //case:aa
      if(s[k] == 'a'+i) prei++;
      //else if(s[k] == 'a'+j) sum+= prei;
    }
    ans = max(ans, sum);
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

/*
5
aaabb
usaco
lol
aaaaaaaa
aaaaaaaaaaaaaaabb
*/
