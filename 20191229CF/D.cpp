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

int T, n, k;
const int maxn = 500+5;
int q[maxn];


signed main()
{
  cin >> n >> k;
  set<int> pool;
  rep(s, 0, n)
  {
    cout << "?";
    rep(i, 0, k) cout << ' ' << (s+i)%n;
    cout << endl;
    int idx, val;
    cin >> idx >> val;
    pool.insert(val);
  }
  cout << "! " << pool.size() << endl;

  return 0;
}
