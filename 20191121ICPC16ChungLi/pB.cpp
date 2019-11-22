#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int T;
int D;
LL x[5000+5];
LL y[5000+5];

LL dis2(int i, int j)
{
  return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}

int main()
{
  cin.tie(0);
  cin >> T;
  while(T--)
  {
    cin >> D;
    for(int i = 0; i < D; i++) cin >> x[i] >> y[i];
    LL mind = dis2(0, 1);
    int idx1 = 0;
    int idx2 = 1;

    for(int i = 0; i < D; i++)for(int j = i+1; j < D; j++)
    {
      if(dis2(i,j)<mind) {mind = dis2(i,j); idx1 = i; idx2 = j;}
      //if(dis2(i,j) == 2) {mind == 2; break;}
    }
    //double ans;
    //if(mind == 2) ans = 1.41; //**+*
    //if(mind == 1) ans = 2.41;
    //else
    //{
    //double xm = (x[idx1]+x[idx2])/2.0;
    //double ym = (y[idx1]+y[idx2])/2.0;
    //double ans = 0;
    //ans += sqrt((x[idx1]-xm)*(x[idx1]-xm)+(y[idx1]-ym)*(y[idx1]-ym));
    //ans += sqrt((x[idx2]-xm)*(x[idx2]-xm)+(y[idx2]-ym)*(y[idx2]-ym));
    double ans = sqrt(dis2(idx1,idx2));
    ans = ans*100;
    LL ansl = LL(ans);
    ans = ansl/100.0;
    //}
    cout << fixed << setprecision(2)<< ans << endl;
  }
  return 0;
}
