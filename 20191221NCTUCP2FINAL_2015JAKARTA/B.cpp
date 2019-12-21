#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int T;
ll x;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> T;
  for(int t = 1; t <= T; t++)
  {
    cin >> x;
    bool flag = 1;
    if(x == 0 || x == 14 || x == 34) flag = 0;
    ll r = (x-4)%34;
    if(r == 0 || r == 4 || r == 16 || r == 20 || r == 24 ) flag = 0;
    cout << "Case #" << t <<  ": " << (flag?"UDIN":"UCOK") << endl;
  }
  return 0;
}
