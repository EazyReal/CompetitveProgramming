#include <bits/stdc++.h>

using namespace std;

int n , s, p_tmp, t;
double p, q;
double eps = 0.00001;


//#define USESTD

#ifdef USESTD
#define fsin cin
#define fsout cout
#endif
#ifndef USESTD
fstream fsin("betting.in",ios::in);
fstream fsout("betting.out",ios::out);
#endif
//fstream fsin("betting.in");
//fstream fsout("betting.out",fstream::out);

double P(int t, int s, int n)
{
  //if() return P[t][s][n];
  if(t < 0 || s <= 0) return 0.0;
  if(t == 0) return double(s>=n);
  if(s >= n) return 1.0;
  if((log2(n/s) - t) > eps) return 0.0;
  if(s <= n/2) return p*P(t-1, s*2, n);
  return p + q*P(t-1, s-(n-s), n);
}



int main()
{
  fsout.precision(15);
  while(fsin >> n >> s >> p_tmp >> t)
  {
    if(n == 0 && s == 0) return 0;
    p = p_tmp/100.0;
    q = 1.0-p;
    fsout << fixed << P(t, s, n) << endl;
  }
  return 0;
}
