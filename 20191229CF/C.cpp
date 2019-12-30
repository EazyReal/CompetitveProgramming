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
const int maxn = 1e5+10;
ll a[maxn];

//s+k = 2*(xorsum^k)
//k , 2k2
//s+k(even)/2 + k2 = xorsum^k^(2*k2)
//

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--)
    {
      cin >> n;
      ll sum = 0ll;
      ll xorsum = 0ll;
      ll a;
      rep(i, 0, n)
      {
        cin >> a;
        sum += a;
        xorsum ^= a;
      }
      ll k1 = sum%2ll;
      ll sum2 = sum+k1;
      ll xorsum2 = xorsum^k1;
      ll k2 = xorsum2;
      ll sum3 = sum2+k2;
      ll xorsum3 = xorsum2^k2;
      ll k3 = sum3;
      assert(sum+k1+k2+k3 == 2*(xorsum^k1^k2^k3));
      cout << 3 << endl << k1 << ' ' << k2 << ' '  << k3 << ' ' << endl;
    }

    return 0;
}
