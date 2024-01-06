#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int T;
LL m, n, k, t;
const int maxm = 100000+5;
const int maxk = 100000+5;
LL a[maxm];

struct Trap
{
  int l, d, r;
}traps[maxk];

bool cmp(const Trap& a, const Trap &b)
{
  return (a.l < b.l) || ((a.l == b.l)&&(a.r > b.r)); //bug1
}

//observation, t depends only on soldier with minimal ai
//binary search on the minimal ai solder

//not so trivial so that greedy will fail?

bool C(LL a, LL t)
{
  LL sum = n+1;
  //int ps = traps[0].l-1; //pos soldier waiting
  int pp = 0; //pos player
  int id = 0; //trap id now
  while(id < k) //bug2 k->m...
  {
    if(a >= traps[id].d || pp >= traps[id].r) { id++; continue;}
    //need to remove trap, alse move out along the way
    pp = max(pp, traps[id].r);
    sum += 2* (traps[id].r-traps[id].l+1);
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
    for(int i = 0 ; i < k; i++) cin >> traps[i].l >> traps[i].d >> traps[i].r;
    sort(a, a+m, greater<LL>());
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
