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

string s;
int q;
int l, r;

//start != end => ok
//a...............b
//b...............a

//if start == end?
//a...........a
//can only b.........c
//abca
//caab
//gues contains 2 up inside(total 4)
//a....b....c....a
//c....a....a....b

int st[200005*4][30];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in", "r", stdin);
    cin >> s;

    for (int i = 0; i < s.size(); i++)
        st[i][0] = (1 << (s[i]-'a'));

    for (int j = 1; j <= 30; j++)
        for (int i = 0; i + (1 << j) <= s.size(); i++)
            st[i][j] = st[i][j-1] | st[i + (1 << (j - 1))][j - 1];

    cin >> q;
    while(q--)
    {
      cin >> l >> r;
      if(l == r) cout << "Yes\n"; //this is sure
      else{
        if(s[l-1] != s[r-1]) cout << "Yes\n"; //0-indexed //this is sure
        else
        {
          l--; r--;
          int sum = 0;
          for (int j = 30; j >= 0; j--) {
              if ((1 << j) <= r - l + 1) {
                  sum |= st[l][j];
                  l += 1 << j;
              }
          }
          if(__builtin_popcount(sum) >= 3) cout << "Yes\n";
          else cout << "No\n";
        }
      }
    }

    return 0;
}
