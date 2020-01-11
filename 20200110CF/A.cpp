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
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif
    cin >> n;
    string str;
    cin >> str;
    int nL = 0;
    int nR = 0;
    rep(i, 0, n) {if(str[i] == 'L') nL ++; else nR++;}
    cout << 1+nL+nR << endl;
    return 0;
}
