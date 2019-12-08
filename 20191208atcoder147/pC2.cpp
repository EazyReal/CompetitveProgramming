#include <bits/stdc++.h>

using namespace std;
#define pb push_back

typedef long long ll;
 //__builtin_popcount(unsigned int)
int n;
int a[15+5][15+5];
//int mark[15+5];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n;
  int ai, ta, tb;
  memset(a, -1, sizeof(a));
  for(int i = 1; i <= n; i++)
  {
    cin >> ai;
    for(int j = 0; j < ai; j++)
    {
      cin >> ta >> tb;
      a[i][ta] = tb?1:0;
    }
  }
  //for(int i = 1; i <= n; i++, cout <<endl)for(int j = 1; j <= n; j++) cout << a[i][j] << ' ';
  int ans = 0; //max
  for(unsigned int  s = 0; s < (1<<n); s++)
  {
    //cout << "now at state " << s << endl;
    bool flag = 0;
    for(int i = 1; i <= n; i++)if((s>>(i-1))&1)
    {
      //cout << "now at rule from " << i << endl;
      for(int j = 1; j <= n; j++)
      {
        if(a[i][j] != -1)
        {
          bool tmp = (s>>(j-1))&1;
          //cout << "now at " << j <<  " tmp is " << tmp << endl;
          if(tmp != a[i][j])
          {
            flag = 1;
            //cout << "contradiction @ " << i << ' ' << j << endl; //rule of i at j
          }
        }
      }
      if(flag) break;
    }
    if(flag) continue;
    else ans = max(ans, __builtin_popcount(s));
  }
  cout << ans << endl;
  return 0;
}
