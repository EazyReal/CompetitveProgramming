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
int k1, k2;
const int maxn = 100+5;
int a[maxn];
int b[maxn];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--)
    {
      cin >> n >> k1 >> k2;
      int max1 = 0, max2 = 0;
      rep(i, 0, k1) cin >> a[i], max1 = max(max1, a[i]);
      rep(i, 0, k2) cin >> b[i], max2 = max(max2, b[i]);
      cout << ((max1 > max2)? "YES\n":"NO\n");
    }
    return 0;
}
