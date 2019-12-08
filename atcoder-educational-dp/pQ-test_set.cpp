#include <bits/stdc++.h>

using namespace std;
#define pb push_back

typedef long long ll;

int n;
const int maxn = 2e5+5;
const int maxa = 1e9;
ll MOD = 1e9+7;
ll a[maxn];
int h[maxn];
ll dp[maxn];
int pos[maxn];


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n;
  set<int, greater<int> > s;
  for(int i = 0; i < n; i++)
  {
    if(i!=n-5) s.insert(i);
  }
  cout << *s.lower_bound(n-5) << endl;

  return 0;
}
