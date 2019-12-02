#include <bits/stdc++.h>

using namespace std;

int T, n;
int a, b;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while(T--)
  {
    cin >> a >> b;
    if(a == 0 && b == 0) {cout << "YES" << endl; continue;}
    if(a<b) swap(a,b);
    //a = 2x+y, b = y+2x
    int s = a+b;
    if(s%3 != 0) {cout << "NO" << endl; continue;}
    int sxy = s/3;
    int dxy = a-b;
    if((sxy+dxy)%2 == 1) {cout << "NO" << endl; continue;}
    int x = (sxy+dxy)/2;
    int y = sxy-x;
    if(x < 0 || y < 0) cout << "NO" << endl; //either one is 0 is ok
    else cout << "YES" << endl;

  }
  return 0;
}
