#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back

int T;
LL m, n, k, t;
const int maxn = (1<<18)+1;
LL a[maxn];
int vis[maxn];


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
    priority_queue<pii> pq;;
    memset(vis, -1, sizeof(vis));
    cin >> n;
    int frd;
    bool flag = 0;
    for(int i = 0; i < n; i++)
    {
      cin >> a[i];
      if(a[i] == -1) {frd = i; flag = 1; continue;}
      if(!flag) {pq.push(pii(0,i)); a[i] = 0;}
      else pq.push(pii(a[i], i));
    }
    //if(frd == n-1) {cout << 0 << endl; continue;}
    LL sum = 0;
    int reversed_round = 0;
    int cur_strongest = n-1;
    while(!pq.empty() && cur_strongest > frd)
    {
      for(;vis[cur_strongest]==1;cur_strongest--); //find unvisited strongest
      if(cur_strongest <= frd) break;
      vis[cur_strongest] = 1;
      sum += a[cur_strongest];
      //cout << reversed_round << "th round "<< sum << endl;
      int to_remove = (n/(1<<reversed_round)-2)/2;
      //cout <<  to_remove << " to remove\n";
      reversed_round++;
      int removed = 0;
      while(removed < to_remove)
      {
        pii x = pq.top(); pq.pop();
        if(!~vis[x.Y]) {removed++; vis[x.Y] = 1;}
      }
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
