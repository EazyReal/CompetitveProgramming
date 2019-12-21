#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int maxn = 100;


int main()
{
  cin >> maxn;
  vector<int> sg({0,1,1,2,0,3});
  sg.resize(maxn+1);
  //for(int x = 0; x < 5; x++, cout << endl) cout << sg[x];
  for(int x = 6; x <= maxn; x++)
  {
    set<int> s;
    s.insert(sg[x-2]);
    //s.insert(sg[x-3]);
    for(int i = 0; i < x/2; i++)
    {
      if(x-i-3<0) break;
      s.insert(sg[i]^sg[x-i-3]);
    }
    int cur_sg = 0;
    for(int i = 0; i <= maxn; i++)
    {
      if(s.find(i)==s.end()) {cur_sg = i; break;}
    }
    sg[x] = cur_sg;
  }
  for(int x = 0; x <= maxn; x++, cout << endl)
  cout << x << ' ' << sg[x] << ' ';
  return 0;
}
