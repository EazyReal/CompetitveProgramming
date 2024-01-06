#include <bits/stdc++.h>

using namespace std;

int w, h;

//#define USESTD

#ifdef USESTD
#define fsin cin
#define fsout cout
#endif
#ifndef USESTD
fstream fsin("funny.in",ios::in);
fstream fsout("funny.out",ios::out);
#endif

int prime_cnt(int x)
{
  int cnt = 0;
  int y = x;
  if(x == 0) return 0;
  for(int i = 2; i*i <= y; i++)
  {
    while((x%i) == 0) {x/=i; cnt++;}
  }
  if(x>1) cnt++; //is prime
  return cnt;
}

int main()
{
  while(fsin >> w >> h)
  {
    if(w == 0 && h == 0) return 0;
    else fsout << w << ' ' << h << " - " << ((prime_cnt(w) > prime_cnt(h)) ? "Vera" : "Harry") << endl;
  }
  return 0;
}
