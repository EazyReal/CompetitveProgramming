#include <bits/stdc++.h>

using namespace std;

int T, n;
int c, s;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while(T--)
  {
    cin >> c >> s;
    if(c >= s)
    {
      cout << s << endl;
    }else{
      int a = s/c;
      int b = s%c;
      int ans = (c-b)*a*a + b*(a+1)*(a+1);
      cout << ans << endl;
    }

  }
  return 0;
}
