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
const int maxn = 2e5+7;


struct Book
{
  int score;
  int pri;//*
};

//more occurence => smaller pri
//occurence in high book count library => less contribution to pri


struct Library
{
  int n, t, m; //n=bl.size()
  set<int> bl;
  int pri; //sum of bl's pri, m, t
  //c1 * sigma pri + c2 * m + c3 * t
};

//contains rare book => high pri
//contains more book => high pri

int B, L, D;

template<class T>
bool compare(const T& a, const T& b)
{
   return a.pri < b.pri;
}


vector<Book> b;
vector<Library> l;

signed main()
{
  // freopen("", "r", stdin);
  // freopen("", "w", stdout);
  cin >> B >> L >> D;
  b.resize(B);
  l.resize(L);
  for(auto& bi : b) cin >> bi;
  for(auto& li : l)
  {
    assert(bl.empty());
    cin >> li.n >> li.t >> li.m;
    for(int i = 0; i < li.n; ++i)
    {
      int tmp;
      cin >> tmp;
      bl.insert(tmp);
    }
  }
  sort(all(l)); //some sorting according to pri Library

  rep(i, 0, l)
  {

  }



};


//deter library val from book O(B)
//deter book val from library O(B*L) 10^10
//l->b->l->b converge k
//k*10 second
