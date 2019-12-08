#include <bits/stdc++.h>

using namespace std;
#define pb push_back

typedef long long ll;

int n;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  string s;
  cin >> s;
  int ans = 0;
  for(int i = 0; i < s.size()/2; i++)
  {
    if(s[i] != s[s.size()-1-i]) ans++;
  }
  cout << ans << endl;
  return 0;
}
