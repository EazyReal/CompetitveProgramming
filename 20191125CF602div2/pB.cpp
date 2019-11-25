#include <bits/stdc++.h>

using namespace std;

int T, n;
const int maxn = 100000+5;

bool vis[maxn];
int minv;
int maxv;
int q[maxn]; //no need
int a[maxn];
bool flag;

int main()
{
  cin >> T;
  while(T--)
  {
    cin >> n;
    memset(vis, 0, sizeof(vis));
    minv = 1;
    flag = 0;
    for(int i = 0; i < n; i++) cin >> q[i];
    a[0] = q[0];
    vis[a[0]] = 1;
    for(int i = 1; i < n; i++)
    {
      if(q[i] == q[i-1])
      {
        while(vis[minv] != 0) minv++;
        if(minv > q[i]) {flag = 1; break;}
        else{a[i] = minv; vis[minv] = 1; minv++;}
      }else if (q[i] < q[i-1]){
        flag = 1; break;
      }else{
        a[i] = q[i];
        vis[q[i]] = 1;
      }
    }
    if(flag) cout << -1 << endl;
    else{
      for(int i = 0; i < n; i++) cout << a[i] << " \n"[i==n-1];
    }
  }
  return 0;
}
