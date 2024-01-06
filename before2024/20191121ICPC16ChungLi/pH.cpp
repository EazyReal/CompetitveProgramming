#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20+5;
int T;
int n, m;
int A[MAXN][MAXN];

void print()
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      cout << A[i][j] << ((j==n-1)?'\n':' ');
    }
  }
}

bool Gauss() {
  for(int i = 0; i < n; i++) {
    bool ok = 0;
    for(int j = i; j < n; j++) {
      if(A[j][i] > 0) {
        swap(A[j], A[i]);
        ok = 1;
        break;
      }
    }
    if(!ok) return 0;
    //int fs = A[i][i];
    for(int j = i+1; j < n; j++) {
        int r = A[j][i] ;// / fs;
        for(int k = i; k < n; k++) {
          //A[j][k] -= A[i][k] *r;
          A[j][k] ^= (A[i][k]&&r);
        }
    }
    //print();
  }
  return 1;
}

int main()
{
  cin >> T;
  while(T--)
  {
    cin >> n >> m;
    n = n/2;
    int ti, tj;
    memset(A, 0, sizeof(A));
    for(int i = 0; i < m; i++)
    {
      cin >> ti >> tj;
      bool flag;
      --ti;
      if(ti >= n) {ti-=n; flag = 0;}
      --tj;
      if(tj >= n) {tj-=n; flag = 1;}
      if(flag) A[ti][tj] = 1;
      else A[tj][ti] = 1;
    }
    bool ended = Gauss();
    int res = 1;
    for(int i = 0; i < n; i++)
    {
      res = res * A[i][i];
    }
    if(!ended) res = 0;
    cout << 1-(res%2) << endl;
  }
  return 0;
}

/*
2
10 5
1 6
2 7
3 8
4 9
5 10
10 7
1 6
1 7
2 6
2 7
3 8
4 9
5 10

*/
