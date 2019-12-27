#include <bits/stdc++.h>

using namespace std;
int T;
int r, g, b;

int main()
{
  cin >> T;
  while(T--)
  {
    cin >> r >> g >> b;
    int maxv = max(r, max(g, b));
    int sum = r+g+b;
    bool ok = maxv <= sum-maxv+1;
    cout << (ok?"YES":"NO") << endl;
  }
  return 0;
}
