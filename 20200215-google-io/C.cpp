#include <bits/stdc++.h>
//WA, once considered dp on cur is who's end
//not enough time to think and complete in constest for D seemed more promising

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
int n;

void solve(int ti)
{
  string s;
  cin >> s;
  int n = s.size();
  stack<int> stk[2];//i I
  vector<int> lastIO(4, -1);//io iO Io IO;
  int ans = 0;
  rep(i, 0, n)
  {
    if(s[i] == 'i'){
      stk[0].push(i);
    }
    else if(s[i] == 'I'){
      stk[1].push(i);
    }
    else if(s[i] == 'o'){
      if(!stk[0].empty() && stk[0].top() > lastIO[0])
      {
        lastIO[0] = i;
        stk[0].pop();
      }else if(!stk[1].empty() && stk[1].top() > lastIO[2])
      {
        lastIO[2] = i;
        stk[1].pop();
      }else{
        assert(false);
      }
    }
    else if(s[i] == 'O'){
      if(!stk[1].empty() && stk[1].top() > lastIO[3])
      {
        lastIO[3] = i;
        stk[1].pop();
        ans++;
      }else if(!stk[0].empty() && stk[0].top() > lastIO[1])
      {
        lastIO[1] = i;
        stk[0].pop();
      }else{
        assert(false);
      }
    }
  }
  cout << "Case #" << ti << ": ";
  cout << ans << endl;
  return;
}


signed main()
{
  fastIO();
  cin >> T;
  //T = 1;
  rep(ti, 1, T+1) solve(ti);
  return 0;
}
