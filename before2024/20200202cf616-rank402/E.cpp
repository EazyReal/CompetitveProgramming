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
int n, k;
string s;
const int maxn = 300005;
vector<int> edge[maxn];
vector<int> subsets[maxn];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in", "r", stdin);
    cin >> n >> k;
    cin >> s;
    int c, xi;
    rep(i, 0, k)
    {
      cin >> c;
      rep(i, 0, c)
      {
        cin >> xi;
        edge[xi].pb(i);
        subsets[i].pb(xi);
      }
    }
    return 0;
}
