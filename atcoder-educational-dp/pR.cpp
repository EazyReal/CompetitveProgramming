#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll k;
const int maxn = 50+5;
const ll maxk = 1e18;
const ll MOD = 1e9+7;
ll a[maxn][maxn];

class Matrix //square matrix
{
public:
  int n;
  ll a[maxn][maxn];

  Matrix(int n)
  {
    this->n = n; //use global ok?
    memset(a, 0ll, sizeof(a));
  }
  Matrix operator * (Matrix const& rhs) //n*n
  {
    Matrix res(n);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    {
      res.a[i][j] = 0ll;
      for(int k = 0; k < n; k++)
        res.a[i][j] += a[i][k]*rhs.a[k][j], res.a[i][j] %= MOD; //MOD not in for
    }
    return res;
  }
  friend ostream& operator<<(ostream&, const Matrix&);
};

ostream& operator<<(ostream& out, const Matrix& A) {
  int n = A.n;
  for(int i = 0; i < n; i++, cout << endl)for(int j = 0; j < n; j++)
    cout << A.a[i][j] << ' ';
  return out;
}

Matrix fastpow(Matrix A, ll k)
{
  Matrix ret(n);
  for(int i = 0; i < n; i++) ret.a[i][i] = 1ll;
  //cout << ret;
  for(;k;k>>=1)
  {
    if(k&1ll) ret = ret*A;
    A = A*A;
  }
  //cout << ret;
  return ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n >> k;
  Matrix A(n);
  for(int i = 0; i < n; i++)for(int j = 0; j < n; j++) cin >> A.a[i][j];
  //cout << A;
  Matrix ret(n);
  ret = fastpow(A, k);
  ll sum = 0ll;
  for(int i = 0; i < n; i++)for(int j = 0; j < n; j++)
    sum = (sum + ret.a[i][j])%MOD;
  cout << sum << endl;

  return 0;
}
