//69306579	Jan/22/2020 22:40UTC+8	maxwill	A - Collecting Coins	GNU C++17	Accepted	46 ms	4 KB
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
      ll a, b, c, n;
      cin >> a >> b >> c >> n;
      bool flag = true;
      if((a+b+c+n)%3 != 0) flag = false;
      ll avg = (a+b+c+n)/3ll;
      if(a > avg || b > avg || c > avg) flag = false;
      cout << (flag?"YES":"NO") << endl;
    }

    return 0;
}
