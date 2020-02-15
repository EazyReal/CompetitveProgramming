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
const int maxn = mod;
int n, m;
string ss[100+5];
int pairs[100+5];
vector<int> ans;

bool isPalindrome(string &str){
  int len = str.length();

  for(int i = 0; i < len/2; i++){
      if(str[i] != str[len-1-i]){
          return false;
      }
  }
  return true;
}

bool isReverse(int a, int b)
{
  int len = m;
  rep(i, 0, len)
  {
    if(ss[a][i] != ss[b][len-1-i]) return false;
  }
  return true;
}

void solve()
{
  cin >> n >> m;
  rep(i, 0, n) cin >> ss[i];
  rep(i, 0, n) pairs[i] = -1;
  int cnt = 0;
  ans.clear();
  //debug(res);
  rep(i, 0, n)rep(j, i+1, n)
  {
    if(isReverse(i, j))
    {
      if(pairs[i] == -1){ans.pb(i); cnt++;}
      pairs[i] = j;
      pairs[j] = i;
    }
  }
  //assert(cnt%2 == 0);
  int oddone = -1;
  rep(i, 0, n)
  {
    if(pairs[i] == -1 && isPalindrome(ss[i])){
      oddone = i; break;
    }
  }
  //debug(cnt);
  cout << (2*cnt + int(oddone!=-1))*m << endl;
  rep(i, 0, cnt) cout << ss[ans[i]];
  if(oddone != -1) cout << ss[oddone];
  repinv(i, 0, cnt) cout << ss[pairs[ans[i]]];
  cout << endl;
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
4
3 3
tab
one
bat

4 2
oo
ox
xo
xx

3 5
hello
codef
orces

9 4
abab
baba
abcd
bcde
cdef
defg
wxyz
zyxw
ijji
*/
