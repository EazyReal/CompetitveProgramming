#include <bits/stdc++.h>

using namespace std;
#define pb push_back

typedef long long ll;

int n;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int a1, a2, a3;
  cin >> a1 >> a2 >> a3;
  cout << (((a1+a2+a3)>=22)?"bust":"win") << endl;

  return 0;
}
