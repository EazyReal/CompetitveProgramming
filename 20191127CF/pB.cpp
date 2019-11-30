#include <bits/stdc++.h>

using namespace std;

int T, n;
int a, b;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while(T--)
  {
    cin >> a >> b;
    if(a == b && (a%3==0)) cout << "YES" << endl;
    else if (a != b && (a == 0 || b == 0)) cout << "NO" << endl;
    else{
      bool flag = false;
      if(a<b) swap(a, b);
      for(int x = 0; x <= a && (x<<1) <= b; x++)if(((a-x)&1)==0)
      {
        int y = (a-x)>>1;
        if(b == y+(x<<1))
        {
          flag =true;
          cout << "YES" << endl;
          break;
        }
      }
      if(flag == false) cout << "NO" << endl;
    }

  }
  return 0;
}
