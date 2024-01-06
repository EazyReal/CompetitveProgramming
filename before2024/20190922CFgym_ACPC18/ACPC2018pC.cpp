#include <cstdio>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int T, C, P;
string tmp;
string p;
string sz;
struct Price{
  int s, m,l;
};

int main()
{

  //freopen("dull.in", "r", stdin);
  scanf("%d", &T);
  scanf("%d%d", &C, &P);
  while(T--)
  {
    map<string, Price> mm;
    for(int i = 0; i < C; i++)
    {
      cin >> tmp;
      Price tmpp;
      cin >> tmpp.s >> tmpp.m >> tmpp.l;
      mm[tmp] = tmpp;
    }
    for(int i = 0; i < P; i++)
    {
      cin >> p;
      cin >> sz;
      cin >> tmp;
      int ans = 100/P;
      if(sz[0] == 's') ans += mm[tmp].s;
      if(sz[0] == 'm') ans += mm[tmp].m;
      if(sz[0] == 'l') ans += mm[tmp].l;
      if(ans%5 == 1) ans--;
      if(ans%5 == 4) ans++;
      cout << p << ' ' << ans << endl;
    }
  }

  return 0;
}
