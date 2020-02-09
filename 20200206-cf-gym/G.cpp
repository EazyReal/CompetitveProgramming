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

#include<ext/rope>
using namespace __gnu_cxx;

int T, n;
const int maxn = 200000+5;
rope<int> *q[maxn];

#define ONLINE

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifdef ONLINE
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);
    #endif

    cin >> n;
    q[0] = new rope<int>;
    int op, ver, val;
    rep(i, 1, n+1)
    {
      cin >> op;
      if(op == 1)
      {
        cin >> ver >> val;
        q[i] = new rope<int>(*q[ver]);
        q[i]->pb(val);
      }else if(op == -1){
        cin >> ver;
        q[i] = new rope<int>(*q[ver]);
        cout << q[i]->at(0) << endl;
        q[i]->erase(0, 1);
      }
    }


    return 0;
}
