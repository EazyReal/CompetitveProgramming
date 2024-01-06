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

int T;
ll n, d;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--)
    {
      cin >> n >> d;
      ll sq = int(sqrt(d));
      //if (sq*sq == d) sq++;
      //debug(sq);
      bool flag = false;
      //rep(i, -100ll, sq-1)
      if(sq-1+d/sq+(d%sq>0?1:0) <= n) flag = true;
      cout << (flag?"YES":"NO") << endl;
    }
    return 0;
}
