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

const ll MOD = 1e9;
const int maxn = (1<<8)+1;

inline void add(ll &x, ll dx) //add
{
  x = ((x+dx)%MOD+MOD)%MOD;
}

class Matrix //n*n matrix
{
public:
    ll a[maxn][maxn];
    int n;
    Matrix() {};
    Matrix(int n) :n(n) {rep(i, 0, n)rep(j, 0, n) a[i][j] = 0ll;};
    Matrix(int n, bool type) :n(n) //for I
    {
      rep(i, 0, n)rep(j, 0, n) a[i][j] = ll(type && i==j);
    };
    Matrix operator *(const Matrix &rhs);
    ll* operator [](int i){return a[i];}
    void operator =(const Matrix &rhs);
    Matrix operator ^(ll k);

    friend ostream& operator <<(ostream &os, const Matrix &rhs);
};

ostream& operator<<(ostream& os, const Matrix& rhs)
{
    rep(i, 0, rhs.n)
    {
      rep(j, 0, rhs.n) cout << rhs.a[i][j] << ' ';
      cout << endl;
    }
    return os;
}

Matrix Matrix::operator *(const Matrix &rhs)
{
    Matrix ret(n);
    rep(i, 0, n)rep(j, 0, n)
    {
      ret.a[i][j] = 0ll;
      rep(k, 0, n) add(ret.a[i][j], (a[i][k]*rhs.a[k][j])%MOD);
    }
    return ret;
}

void Matrix::operator =(const Matrix &rhs)
{
  n = rhs.n;
  rep(i, 0, n)rep(j, 0, n) a[i][j] = rhs.a[i][j];
}

Matrix Matrix::operator ^(ll k)
{
  cout << "in ^";
  Matrix ret(n, 1);
  Matrix tmp = *this;
  for(;k;k>>=1ll)
  {
    if(k&1ll) ret = ret*tmp;
    tmp = tmp*tmp;
  }
  return ret;
}

ll T, n, m;

//build transition
//1 = gap that need to use 2*1 after!
void build(Matrix &M, int d, int before , int after)
{
  //debug(d);
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
    Matrix M(1<<n, 0);
    build(M, 0, 0, 0);
    debug(M);
    cout << ((M^m)[0][0]) << endl;
    return 0;
}
