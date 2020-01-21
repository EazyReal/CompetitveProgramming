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

const ll MOD = 1e9+7;
const int maxn = 4;

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
  Matrix ret(n, 1);
  Matrix tmp = *this;
  for(;k;k>>=1)
  {
    if(k&1) ret = ret*tmp;
    tmp = tmp*tmp;
  }
  return ret;
}

int T;
ll l, r, k;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    rep(t, 1, T+1)
    {
      cin >> l >> r >> k;
      Matrix f(2); //fabonocii matrix
      f[0][0] = 1; f[0][1] = 1; f[1][0] = 1; f[1][1] = 0;
      Matrix fk(2);
      fk = f^k;
      //cout << fk;
      Matrix sumk(3); //sum every k
      sumk[0][0] = fk[0][0]; sumk[0][1] = fk[0][1];
      sumk[1][0] = fk[1][0]; sumk[1][1] = fk[1][1];
      sumk[2][0] = fk[0][0]; sumk[2][1] = fk[0][1]; sumk[2][2] = 1ll;
      //cout << sumk;
      ll ln = (l-1)/k; ll rn = r/k;
      Matrix lm = sumk^ln;
      Matrix rm = sumk^rn;
      //cout << rm;
      ll rcnt = (rm[2][0]+rm[2][1])%MOD;
      ll lcnt = (lm[2][0]+lm[2][1])%MOD;
      cout << "Case " << t << ": " << ((rcnt-lcnt)%MOD+MOD)%MOD << endl;
    }
    return 0;
}
