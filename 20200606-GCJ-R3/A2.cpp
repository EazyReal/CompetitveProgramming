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
string C, J;
string ANS;
int n, m;
//ll a[maxn];

vector<vector<int>> dp; 
vector<vector<int>> path; 


void build_path(int i, int j, int pos, string cur, vector<string> &p)
{
    if(i == 0)
    {
        while(j > 0){
            cur.erase(pos,1);
            pos = max(pos-1,0);
            p.pb(cur);
            j--;
		}
        return;
    }
    if(j == 0){
        while(i > 0){
            cur.insert(0,1,C[i-1]);
            p.pb(cur);
            i--;
		}
        return;
    }
    if(path[i][j] == -1)
    {
        //debug(-1);
        build_path(i-1, j-1, max(pos-1,0), cur, p);
        return;
    }
    if(path[i][j] == 1) //remove J
    {
        //debug(1);
        cur.erase(pos,1);
        p.pb(cur);
        build_path(i, j-1, max(pos-1, 0),cur, p);
        return;
    }
    if(path[i][j] == 2) //insert C
    {
        //debug(2);
        if(pos+1 == cur.size()) cur.pb(C[i-1]);
        else cur.insert(pos+1,1,C[i-1]);
        p.pb(cur);
        build_path(i-1, j,pos,cur, p);
        return;
    }
    if(path[i][j] == 3) //change
    {
        //debug(3);
        cur[pos] = C[i-1];
        p.pb(cur);
        build_path(i-1, j-1, max(pos-1, 0), cur, p);
        return; 
    }
    return;
}

//check T
void solve()
{
  cin >> C;
  cin >> J;
  n = C.size();
  m = J.size();

  int maxb = 65;
  //sample RE
  //dp.resize(n+1, vector<int>(m+1, 0)); 
  //path.resize(n+1, vector<int>(m+1, 0)); 
  //test2 RE
  //dp.resize(maxb, vector<int>(maxb, 0)); 
  //path.resize(maxb, vector<int>(maxb, 0)); 
  //AC
  dp = vector<vector<int>>(maxb, vector<int>(maxb, 0)); 
  path = vector<vector<int>>(maxb, vector<int>(maxb, 0)); 
  rep(i, 0, n+1)rep(j, 0, m+1)
  {
    if(i == 0) dp[i][j] = j;
    else if(j == 0) dp[i][j] = i;
    else if(C[i-1] == J[j-1])
    {
        dp[i][j] = dp[i-1][j-1];
        path[i][j] = -1;
    }
    else{
        int bestid = 0;
        int bestv = 1000;
        if(dp[i][j-1] < bestv) {bestid = 1; bestv = dp[i][j-1];} //remove J's
        if(dp[i-1][j] < bestv) {bestid = 2; bestv = dp[i-1][j];} //remove C's
        if(dp[i-1][j-1] < bestv) {bestid = 3; bestv = dp[i-1][j-1];} //replace C with J
        dp[i][j] = 1 + bestv; 
        path[i][j] = bestid;
    }
  }
  int total = dp[n][m];
  vector<string> p;
  build_path(n, m, m-1, J, p);
  //debug(J);
  //for(string& s : p) debug(s);
 // debug(C);
  if(p[(total-1)/2].size() != 0) ANS = p[(total-1)/2];
  else ANS = p[(total-1)/2+1];
  //note that dis/2 but care the "", can use dis/2+1
  cout << ANS << endl;
  //assert(p.size() == dp[n][m]);
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
    cout << "Case #" << tc << ": ";
    solve();
  }
  return 0;
}

/*
1
ABCDEF
ACDEFG

ABCDWWW
WWFDG
*/