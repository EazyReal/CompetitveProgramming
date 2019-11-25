#include <bits/stdc++.h>

using namespace std;

int T, n;
const int M = 1000000001;

struct Seg
{
  int l, r;
}seg[100000+5];

bool cmp(Seg a, Seg b)
{
  return ((a.r < b.r) || (a.r==b.r && a.l < b.l));
}
bool cmp2(Seg a, Seg b)
{
  return ((a.l < b.l) || (a.l==b.l && a.r > b.r));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--)
  {
    cin >> n;
    for(int i = 0; i < n; i++)
    {
      cin >> seg[i].l >> seg[i].r;
    }
    sort(seg, seg+n, cmp);
    int s = seg[0].r;
    sort(seg, seg+n, cmp2);
    int t = seg[n-1].l;
    if(t<s) cout << 0 << endl;
    else cout << t-s << endl;
  }
  return 0;
}
