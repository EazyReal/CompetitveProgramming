#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define debug(x) std::cout << #x << ": " << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

typedef vector<vector<ll>> Mat;

const ll MOD = 1e9;

inline void add(ll &x, ll dx) //add
{
  x = ((x+dx)%MOD+MOD)%MOD;
}

void init(Mat& a, int n)
{
  a.resize(n);
  for(auto &ai : a) ai.resize(n);
}

void cp(Mat& a, Mat &b)
{
  int n = b.size();
  a.resize(n);
  for(auto &ai : a) ai.resize(n);
  rep(i, 0, n)rep(j, 0, n) a[i][j] = b[i][j];
}

// a *= b
void Matmul(Mat &a, Mat &b)
{
  int n =  a.size();
  Mat ret; init(ret, n);
  rep(i, 0, n)rep(j, 0, n)
  {
    ret[i][j] = 0ll;
    rep(k, 0, n) add(ret[i][j], (a[i][k]*b[k][j])%MOD);
  }
  cp(a, ret);
}

Mat Matpower(Mat a, ll k)
{
  int n = a.size();
  Mat mul;
  Mat ret;
  cp(mul, a);
  init(ret, n);
  rep(i, 0, n)rep(j, 0, n) if(i==j) ret[i][j] = 1ll;
  for(;k;k>>=1ll)
  {
    if(k&1ll) Matmul(ret, mul);
    Matmul(mul, mul);
  }
  return ret;
}

ll T, n, m;

//build transition
//1 = gap that need to use 2*1 after!
void build(Mat &M, int d, int before , int after)
{
  //debug(d); //debug(n);
  if(d == n) {++M[before][after]; return;}
  before ^= 1 << d; //last no d
  build(M, d+1, before, after);
  before ^= 1 << d; //last has d

  after ^= 1 << d; //dont fill d now
  build(M, d+1, before, after);
  after ^= 1 << d; //fill d now
  build(M, d+1, before, after);
  //fill 2d now(before is 00, after is 00)
  if(d+1 < n) build(M, d+2, before, after);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    Mat M;

    init(M, 1<<n);
    //debug(M.size());
    //debug(M[0].size());
    build(M, 0, 0, 0);
    /*
    rep(i, 0, 1<<n)
    {
      rep(j, 0, 1<<n) cout << M[i][j] << ' ';
      cout << endl;
    }*/
    cout << Matpower(M, m)[0][0] << endl;
    return 0;
}
