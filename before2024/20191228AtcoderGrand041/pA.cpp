#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, a, b;

int main()
{
  cin >> n >> a >> b;
  if(a<b) swap(a, b);
  if((a-b)%2 == 0) cout << (a-b)/2ll<< endl; //including a == b
  else{
    ll ans1 = (n-b)+1;
    ll posa = a + ans1;
    ans1 += (n-posa)/2ll;

    ll ans2 = a-1+1;
    ll posb = b-a ; //posa=0
    ans2 += (posb-1)/2ll;
    cout << min(ans1, ans2);
  }
  return 0;
}
