#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
//for (auto& x : xs)

const int maxn = 300000+5;

int Q;
int a[2][maxn];

char tmp;


int main()
{
  //std::ios::sync_with_stdio(false);
  scanf("%d%c", &Q, &tmp);
  assert(tmp == '\n');
  while(Q--)
  {
    int total = 0;
    int n[2] = {0};
    while(scanf("%c", &tmp))
    {
      if(tmp == '\n') break;
      else
      {
        int v = tmp - '0';
        //printf("%d ", v);
        total++;
        a[v%2][n[v%2]++] = v;
      }
    }
    int h0 = 0; int h1 = 0;
    for(int i = 0; i < total; i++)
    {
      if(h0 == n[0]) {printf("%d", a[1][h1]); h1++;}
      else if(h1 == n[1]) {printf("%d", a[0][h0]); h0++;}
      else{
        if(a[0][h0] < a[1][h1]) {printf("%d", a[0][h0]); h0++;}
        else {printf("%d", a[1][h1]); h1++;}
      }
    }
    printf("\n");
  }


  return 0;
}
