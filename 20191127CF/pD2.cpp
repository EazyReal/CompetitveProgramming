#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define pb push_back

int T;
LL m, n, k, t;
const int maxm = 200000+5;
const int maxk = 200000+5;
LL a[maxm];

struct Trap
{
  LL l, d, r;
}traps[maxk];

bool cmp(const Trap& a, const Trap &b)
{
  return (a.l < b.l) || ((a.l == b.l)&&(a.r < b.r)); //bug1
}

//observation, t depends only on soldier with minimal ai
//binary search on the minimal ai solder

bool C(LL ai, LL t)
{
  LL sum = n+1LL;
  LL pp = -1; //pos player
  for(int i = 0; i < k; i++)
  {
    Trap& trap = traps[i];
    //ignore
    if(ai >= trap.d || pp >= trap.r) {continue;}
    //nxt segment, move
    if(trap.l > pp) {pp = trap.l-1LL;} //move to the trap's l to pick up
    //add cur part(from l to r *2)
    sum += 2LL*(trap.r-pp);
    //remove calculated
    pp = trap.r; // move to the r
  }
  return sum <= t;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  //cin >> T;
  T = 1;
  while(T--)
  {
    cin >> m >> n >> k >>  t;
    for(int i = 0 ; i < m; i++) cin >> a[i];
    for(int i = 0 ; i < k; i++) cin >> traps[i].l >> traps[i].r >> traps[i].d;
    sort(a, a+m, greater<LL>());
    //for(int i = 0 ; i < m; i++) cout << a[i] << endl;
    sort(traps, traps+k, cmp);
    //search on idx;
    int L = -1;
    int R = m;
    int M;
    while(L < R-1)
    {
      M = (L+R)/2;
      if(C(a[M], t)) L = M;
      else  R = M;
    }
    cout << L+1 << endl;
  }
  return 0;
}

/*
5 6 4 20
1 2 3 4 5
1 5 2
1 2 5
2 3 5
3 5 3
5

5 6 4 13
1 2 3 4 5
1 5 2
1 2 5
2 3 5
3 5 3
3

5 6 4 12
1 2 3 4 5
1 5 2
1 2 5
2 3 5
3 5 3
1
*/
