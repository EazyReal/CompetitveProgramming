#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxh = 300000+5;

int T;
int n;
int cur_h;

int BIT[maxh];
int low_bit(int x) {
    return x & -x;
}
void add(int idx, int val) {
    while(idx <= n){
        BIT[idx] += val;
        idx += low_bit(idx);
    }
}
int sum(int idx) {
    int ans = 0;
    while(idx > 0) {
        ans += BIT[idx];
        idx -= low_bit(idx);
    }
    return ans;
}

int  main()
{
  cin >> T;
  for(int t = 1; t <= T; ++t)
  {
    cout << "Case #" << t <<  ":";
    cin >> n;
    cur_h = 1;
    memset(BIT, 0, sizeof(BIT));
    int tmp;
    for(int i = 1; i <= n; ++i)
    {
      cin >> tmp;
      add(tmp , 1);
      if(tmp > cur_h)
      {
        //binary search => pass with nlogn^2
        int L = cur_h;
        int R = i+1;
        int M;
        while(R-L > 1)
        {
          M = (L+R)/2;
          if((i-sum(M-1))>=M) L = M;
          else R = M;
        }
        cur_h = L;
      }
      cout << ' ' << cur_h;
    }
    cout << endl;
  }
  return 0;
}
