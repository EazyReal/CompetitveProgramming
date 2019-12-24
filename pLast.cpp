#include <bits/stdc++.h>

using namespace std;
#define pb push_back

typedef long long ll;

int T;
int n, k;
int s1, f1, s2, f2;
const int maxn = 16;

//min max of 1/2 : left 1/2 (bigger front) (min->max)
//min max of 1*left2/2*left1

/*
double calc(int a)
{
  double b;
  double sc1, sc2, fc1, fc2;
  b = k-a;
  sc1 = s1-a, sc2 = s2-b;
  fc1 = f1-a, fc2 = f2-b;
  double p1 = (sc1/(sc1+sc2))*(fc1/(fc1+fc2));
  double p2 = (sc2/(sc1+sc2))*(fc2/(fc1+fc2));
  double pr1 = double(a)/k;
  double pr2 = double(b)/k;
  double p = pr1*p1+pr2*p2;
  return p;
}
*/

double P(int a)
{
  double b;
  double sc1, sc2, fc1, fc2;
  b = k-a;
  sc1 = s1-a, sc2 = s2-b;
  fc1 = f1-a, fc2 = f2-b;
  double p1 = (sc1/(sc1+sc2))*(fc1/(fc1+fc2));
  double p2 = (sc2/(sc1+sc2))*(fc2/(fc1+fc2));
  return p1+p2;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> T;
  while(T--)
  {
    cin >> s1 >> f1 >> s2 >> f2 >> k;
    int R = min(min(s1, f1),k); // restrict max of a
    int L = max(0, k-min(s2, f2));// restrict min of a
    int M, MM;
    //cout << L <<' ' << R << endl;
    double pL = P(L);
    double pR = P(R);
    int a1;
    int a2 = (pR<pL?R:L);
    bool flag = 1;
    double eps = 1e-7;
    while(L<R)
    {
      //cout << L <<' ' << R << endl;
      if(L+1 == R) {a1 = (P(L) > P(R)-eps)?L:R; flag = 0;break; } //>= => > =eps
      M = (L+R)/2;
      MM = (M+R)/2 + int(M+1==R);
      if(MM == R) {a1 = (P(MM) > P(R)-eps)?MM:R; flag = 0;break; }
      if(P(M) > P(MM)-eps) R = MM;
      else L = M;
    }
    //cout << "flag" << flag << endl;
    if(flag) a1 = M;
    cout << a1 << ' ' << a2 << endl; //min
  }


  return 0;
}

/*
2
3 4 5 6 7
7 7 10 10 4

2 2
4 0
*/
