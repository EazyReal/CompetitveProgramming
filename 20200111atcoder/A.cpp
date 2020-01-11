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
const int maxn = 50+5;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    string s[maxn];
    int t[maxn];
    string X;
    rep(i, 0, n)
    {
      cin >> s[i];
      cin >> t[i];
    }
    cin >> X;
    bool flag = 0;
    int ans = 0;
    rep(i, 0, n)
    {
      if(flag) ans += t[i];
      if(s[i] == X) flag = 1;
    }
    cout << ans << endl;

    return 0;
}
