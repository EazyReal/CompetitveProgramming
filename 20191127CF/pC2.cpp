#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int T, n;
LL r, b, k;

LL gcd(LL a , LL b)
{
  if(a < b) swap(a,b);
  if(b==0) return a;
  a%=b;
  return gcd(b,a);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while(T--)
  {
    cin >> r >> b >> k;
    if(r==1 && b==1) {cout << "OBEY" << endl; continue;}
    //if(r>k && b==1) {cout << "REBEL" << endl; continue;}
    if(r < b) swap(r,b); //r>=b
    LL dd = gcd(r,b);
    LL lcm = r*b*dd;

    if((r/b)-(r%b==0) >= k) cout << "REBEL" << endl;
    else if(dd+(k-1)*b < r) cout << "REBEL" << endl;//wa on 2
    else cout << "OBEY" << endl;

  }
  return 0;
}
