#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
//for (auto& x : xs)

const int maxn = 50+5;

int Q;
int n;
//int a[maxn];
string tmp;
int c0, c1, codd;

int main()
{
  std::ios::sync_with_stdio(false);
  cin >> Q;
  while(Q--)
  {
    cin >> n;
    c0 = 0; c1 = 0; codd = 0;
    for(int i = 0; i < n; i++)
    {
      cin >> tmp;
      //a[i] = tmp.size();
      if(tmp.size()%2 == 1) codd++;
      for(int si = 0; si<tmp.size(); si++)
      {
        if(tmp[si] == '0') c0++; else c1++;
      }
    }
    if(c0%2 == 1 && c1%2 == 1 && codd < 2) cout << n-1 << endl;
    else cout << n << endl;
    //cout << max(0, n-max(0, (c0%2)+(c1%2)-codd)) << endl;
  }


  return 0;
}
