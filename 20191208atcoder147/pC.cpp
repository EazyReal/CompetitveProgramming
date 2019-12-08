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
  for(unsigned int s = 0; s < (1<<n); s++)
  {
    //cout << s << endl;
    //memset(mark, -1, sizeof(mark));
    bool flag = 0;
    for(int i = 1; i <= n; i++)if(s && (1<<(i-1)))
    {
      //cout << "in s" << endl;
      //if(mark[i] == -1) mark[i] = 1;
      //else if(mark[i] == 0) {cout << "as error: "<< i << endl; flag = 1; break;} //marked 0;
      for(int j = 1; j <= n; j++)
      {
        if(mark[j] == -1) mark[j] = a[i][j]; //not marked, mark it
        else if(a[i][j]!=-1 && mark[j] == !a[i][j]) {cout << "ta error" << i << ' ' << j << endl;flag = 1; break;} //marked, contradiction
      }
      if(flag) break;
    }
    if(flag) continue;
    else cout << s << endl, ans = max(ans, __builtin_popcount(s));
  }
  cout << ans << endl;
  return 0;
}
