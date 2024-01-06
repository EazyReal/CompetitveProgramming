#include <bits/stdc++.h>

using namespace std;
#define pb push_back

typedef long long ll;

int T;
int n, k;
const int maxn = 16;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> T;
  while(T--)
  {
    cin >> n >> k;
    ll sum = 0ll;
    ll x;
    for(int i = 0; i < n; ++i) cin >> x, sum += x;
    for(int i = 0; i < k; ++i) cin >> x, sum -= x;
    cout << sum << endl;
  }


  return 0;
}
