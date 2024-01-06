#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
//for (auto& x : xs)

const int maxn = 200000+5;

struct EMP
{
  ull l;
  ull r;
}emp[maxn];

bool cmp(EMP a, EMP b)
{
  return (a.l < b.l) || ((a.l == b.l) && (a.r < b.r));
}

int Q;
ull s;
ull all[2*maxn];

bool C(int M) //let n/2 min l
{
  uul sum = 0;
  for(int i = 0; i < n/2; i++)
  {
    sum += EMP[i].l;
  }
}
//
int main()
{
  std::ios::sync_with_stdio(false);
  cin >> Q;
  while(Q--)
  {
    cin >> n >> s; //n odd assert
    ull maxv = 0;
    for(int i = 0; i < n; i++)
    {
      cin >> emp[i].l >> emp[i].r;
      maxv = max(maxv, emp[i].r)
    }
    //sort(all, all+2*n); //small to large;
    sort(emp, emp+n, cmp);
    ull L = emp[n/2].l; //the n/2+1 th
    ull R = maxv;//the largest r bugg with
    ull M;
    while(L < R)
    {
      M = (L+R)/2;
      if(C(M)) L = M;
      else R = M-1;
    }
    cout << L << endl;
  }


  return 0;
}
