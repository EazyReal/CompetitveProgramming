//69325505	Jan/22/2020 23:04UTC+8	maxwill	C - Product of Three Numbers	GNU C++17	Accepted	31 ms	8 KB
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

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--)
    {
      cin >> n;
      int np = n;
      int count = 0;
      vector<int> a(10);
      for(int x = 2; x*x <= np; x++)
      {
        if(np%x == 0)
        {
          a[count++] = x;
          np/=x;
          if(count == 3) break;
        }
      }
      if(count + int(np!=1) < 3) cout << "NO\n";
      if(count == 2 && np!= 1)
      {
        if(np == a[1]) cout << "NO\n";
        else cout << "YES\n" << a[0] << ' ' << a[1] << ' ' << np << endl;
      }
      else if(count == 3) cout << "YES\n" << a[0] << ' ' << a[1] << ' ' << a[2]*np << endl;
    }

    return 0;
}
