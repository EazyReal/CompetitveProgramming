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

//#define delta[i-1] 0

int T;
int n;
const int maxn = 300005;
int a[maxn];
int hill[maxn];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in", "r", stdin);
    cin >> T;
    while(T--)
    {
      cin >> n;
      //int maxv = -1;
      //int maxpos = -1;
      rep(i, 0, n)
      {
        cin >> a[i];
      }
      /*
      bool flag = 1;
      rep(i, 0, n) if(a[i] < i) flag = 0;
      if(flag) {cout << "Yes\n"; continue;}
      flag = 1;
      rep(i, 0, n) if(a[i] < n-1-i) flag = 0;
      if(flag) {cout << "Yes\n"; continue;}
      */
      //hill
      int idx = 0;
      while(a[idx] >= idx) idx++;
      int top = idx;
      //debug(top); //the first cant -> down
      idx = 0;
      while(a[n-1-idx] >= idx) idx++;
      int top2 = idx;
      //debug(top2);

      if(top + top2 >= n)
      {
        if(top + top2 == n && top == top2 && a[top] == a[n-1-top2]) cout << "NO" << endl;
        else cout << "Yes" << endl;
      }
      else cout << "No" << endl;
    }
    return 0;
}
