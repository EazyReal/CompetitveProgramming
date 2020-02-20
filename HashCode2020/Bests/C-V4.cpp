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
  int id;
  int score;
  double pri;//*
  int freq;
  //int used = 0;
};

//more occurence => smaller pri
//occurence in high book count library => less contribution to pri


struct Library
{
  int n, t, m; //n=bl.size()
  int id;
  vector<int> bl;
  double pri; //priority
  double val; //its val, depends on books
  //c1 * sigma pri * m + c3 * t
};

//contains rare book => high pri
//contains more book => high pri

int B, L, D;

/*
template<class T>
bool compare(const T& a, const T& b)
{
   return a.pri < b.pri;
}
*/

//a front benefit = b.t * a.m

vector<Book> b;
vector<Library> l;
vector<pair<int, vector<int>>> ans;
vector<bool> used;

bool cmp_l(Library &a, Library &b)
{
   return a.pri > b.pri;
   // return a.pri < b.pri;
}

bool cmp_b(int &a, int &rhs)//id
{
  if (used[a]) return 0;
  //return b[rhs].score*b[a].freq < b[a].score*b[rhs].freq;
  return b[a].pri > b[rhs].pri;
}

#define LOCAL
#define FILEO
signed main()
{
#ifdef LOCAL
  freopen("c.txt", "r", stdin);
#endif
#ifdef FILEO
  freopen("c2.out", "w", stdout);
#endif
  cin >> B >> L >> D;
  b.resize(B);
  used.resize(B);
  l.resize(L);

  //cout << "hihi";
  rep(i, 0, B)
  {
    auto &bi = b[i];
    bi.id = i;
    cin >> bi.score;
    bi.freq = 0;
  }
  rep(i, 0, L)
  {
    auto& li = l[i];
    assert(li.bl.empty());
    li.id = i;
    cin >> li.n >> li.t >> li.m;
    for(int i = 0; i < li.n; ++i)
    {
      int tmp;
      cin >> tmp;
      li.bl.pb(tmp);
      b[tmp].freq++;
    }
  }
  rep(i, 0, B) b[i].pri = double(b[i].score/(b[i].freq+1.0));
  rep(i, 0, L)
  {
    l[i].val = 0;
    for(int j = 0; j < l[i].n; ++j)
    {
      l[i].val += b[l[i].bl[j]].pri;
    }
  }
  rep(i, 0, L)
  {
    l[i].pri = 1.0/l[i].t;
  }
  //l
  ans.clear();
  ans.resize(L);
  sort(l.begin(), l.end(), cmp_l);
  //sort(b.begin(), b.end(), cmp_b);
  int curt = 0;
  int curl = 0;
  while(curt < D && curl < L)
  {
    Library &lib = l[curl];
    ans[curl].X = lib.id;
    curt += lib.t;
    if(curt >= D) break;
    //for the library
    int cando = min((D-curt)*lib.m, lib.n); //can process
    //for(auto it = lb.bl.begin(), i = 0; i < cando; i++, it++) {
    //  ans[curl].Y.pb(it->id);
    //}
    sort(lib.bl.begin(), lib.bl.end(), cmp_b);
    for (int i = 0; i < cando; i++)
    {
      ans[curl].Y.pb(lib.bl[i]);
      used[lib.bl[i]] = 1;
    }

    //
    curl++;
  }

  int outn = 0;
  for(auto& ansi : ans) { if(ansi.Y.size()) outn++; }
  cout << outn << endl;
  for(auto& ansi : ans)
  {
    if(ansi.Y.size() == 0) continue;
    cout << ansi.X << ' ' << ansi.Y.size() << endl;
    rep(i, 0, ansi.Y.size())
    {
      cout << ansi.Y[i] << ' ';
    }
    cout << endl;
  }
};
