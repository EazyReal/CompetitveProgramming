#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back

int T;
int n;
const int maxn = (1<<18)+5;
int a[maxn];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  T = 1;
  //cin >> T;
  while(T--)
  //while(cin >> n)
  {
    cin >> n;
    int fid; //friend id
    bool flag = 0;
    for(int i = n; i > 0; i--)
    {
      cin >> a[i];
      if(a[i] == -1) {fid = i; flag = 1; continue;}
      if(!flag) a[i] = 0;
    }

    priority_queue<int, vector<int>, greater<int> > pq;
    LL sum = 0;
    int consider = (n>>1);
    int pos = 1;
    pq.push(a[pos++]);

    while(1)
    {
      int x = pq.top(); pq.pop();
      if(x == -1 || x == 0) break;
      sum += x;
      for(int i = 0; i < consider; i++) pq.push(a[pos++]);
      consider >>= 1;
    }

    cout << sum << endl;
  }
  return 0;
}

/*
8
11 -1 13 19 24 7 17 5
12
*/
