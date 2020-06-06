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
const int maxn = 1e6+7;
int n, p;
int k[maxn];
//int cnt[maxn];//maxk 1e6 too
//const int M = 1000000007;

pair<ll, bool> powmod_detect(ll a,ll b)
{
  bool overflow = 0;
  bool aover = 0;
  ll res=1;
  a%=mod;
  assert(b>=0);
  for(;b;b>>=1){
    if(b&1)
    {
      res=res*a%mod;
      overflow &= res*a >= mod;
      overflow &= aover;
    }
    a=a*a%mod;
    aover &= a*a >= mod;
  }
  return {res, overflow};
}

//check T
void solve()
{
  cin >> n >> p;

  //memset(cnt, 0, sizeof(cnt));
  int maxk = 0;
  rep(i, 0, n)
  {
    cin >> k[i];
    //cnt[ki] ++;
    //maxk = max(ki, maxk);
  }
  sort(k, k+n);
  vector<pii> cnt;
  //int pre = k[0];
  int s = 1;
  rep(i, 1, n)
  {
    if(k[i] != k[i-1]) 
    {
      cnt.pb({k[i-1], s}); //last and s
      s = 1;//the new first
    }else{
      s++;
    }
  }
  cnt.pb({k[n-1], s});

  if(p==1) //special judge p = 1
  {
    cout << n%2 << endl;
    return;
  }

  int ans = 0;
  int wtb = 0; //make sure wtb < n
  //n++;
  repinv(i, 0, cnt.size()) //TLE, multiple task case
  {
    int pk;
    bool bigger = 0;
    //bigger judge no need exact?, id think so
    if(i < cnt.size()-1)
    {
      tie(pk, bigger) = powmod_detect(p, cnt[i+1].X-cnt[i].X);
      wtb = wtb*pk%mod;
      bigger &= wtb*pk >= mod;
      bigger &= wtb > n;
      if(bigger)
      {
        ans = (ans + (wtb+mod-n)*powmod(p, cnt[i].X)%mod)%mod;
        wtb = n;
      } 
    }

    //if(wtb > mod) assert(0);
    /*if(wtb > n)
    {
      ans = (ans + (wtb-n)*powmod(p, i)%mod)%mod;
      wtb = n;
    }*/
    
    if(cnt[i].Y < wtb)
    {
      wtb -= cnt[i].Y;
      continue;
    }else{
      cnt[i].Y -= wtb;
      wtb = 0;
    }
    if(cnt[i].Y%2 == 1) //want to borrow
    {
      //no implement by borrow 
      wtb += 1;
    }
  } 
  ans += (wtb*powmod(p, cnt[0].X)%mod)%mod; //modify
  ans %= mod;
  cout << ans << endl;
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
5 2
2 3 4 4 3
3 1
2 10 1000
4 5
0 1 1 100
1 8
89
*/