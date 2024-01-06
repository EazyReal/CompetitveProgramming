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

int T, n;
const int maxn = 2*1e5 +100;
int a[maxn];

signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while(T--)
  {
    bool flag = 0;
    cin >> n;
    cin >> a[0];
    rep(i, 1, n)
    {
      cin >> a[i];
      if(!flag && abs(a[i]-a[i-1]) > 1) cout << "YES" << endl << i-1+1 << ' ' << i+1 << endl, flag=1;
    }
    if(!flag) cout << "NO\n";
  }
  return 0;
}
