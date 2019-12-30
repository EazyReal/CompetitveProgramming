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
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    bool flag = false;
    //min at left, max at right, crawl it
    int maxi = 0, maxv = a[0];
    int mini = 0, minv = a[0];
    rep(i, 1, n)
    {
      if(a[i] > maxv && a[i]-maxv>i-maxi)
      {
        cout << "YES" << endl << 1 << ' ' << i+1 << endl;
        goto FINISH;
      }

      if(a[i] < minv && minv-a[i]>i-mini)
      {
        cout << "YES" << endl << 1 << ' ' << i+1 << endl;
        goto FINISH;
      }
    }

    //if(maxv-minv>=k) cout << "YES\n1 " << n << endl;
    cout << "NO\n";
    FINISH:
    ll donothing = 0ll;
  }
  return 0;
}
