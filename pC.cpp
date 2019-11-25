#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000+5;
const int maxk = 1000;

int T, n;
int k;

char a[maxn];
char ans[maxn];
int flipl[maxn];
int flipr[maxn];

int main()
{
  ios::sync_with_stdio(false);
  //cin.tie(0);

  cin >> T;
  while(T--)
  {
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < k-1; i++) { ans[2*i] = '('; ans[2*i+1] = ')';}
    for(int i = 2*k-2; i < 2*(k-1)+(n-2*(k-1))/2; i++) ans[i]='(';
    for(int i = 2*(k-1)+(n-2*(k-1))/2; i < n; i++) ans[i] = ')';
    //cout << endl;
    //for(int i = 0; i < n; i++) cout << ans[i] << " \n"[i==n-1];
    int m = 0;
    for(int i = 0; i < n; i++)
    {
      if(ans[i]!=a[i])
      {
        int r;
        for(r = i; r < n; r++) if(a[r]!=a[i]) break;
        flipl[m] = i;
        flipr[m] = r;
        for(int j = 0; j <= (r-i)/2; j++) swap(a[i+j], a[r-j]);
        m++;
      }
    }
    cout << m << endl;
    for(int i = 0; i < m; i++) cout << flipl[i]+1 << ' ' << flipr[i]+1 << endl;
  }
  return 0;
}
