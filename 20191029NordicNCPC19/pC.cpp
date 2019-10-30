#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
  LL n, m, area;
  cin >> n >> m >> area;
  LL a = max(n, m);
  LL b = min(n, m);
  LL a1 = area;
  LL a2 = n*m -area;

  if(a1%a == 0 || a1%b == 0) cout << 1;
  else {
    bool flag = 0;
    for(LL i = 1; i < b ; i++)
    {
      if((a1%i == 0 && a1/i <= a) || (a2%i == 0 && a2/i <= a))
      {
        cout << 2;
        flag = 1;
        break;
      }
    }
    if(!flag) cout << 3;
  }
  return 0;
}
