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
const int maxn = 1e6+5;
int a[maxn];
double ad[maxn];


//lemma: disjoint segments
//from head to tall git min
//how to do this fast for 1e6 n

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in", "r", stdin);
    cin >> n;
    rep(i, 0, n) cin >> a[i], ad[i] = double(a[i]);
    
    return 0;
}
