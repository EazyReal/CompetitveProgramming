#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
//for (auto& x : xs)

const int alpha = 26;

int main()
{
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  //fstream fin("filename.in");
  int T;
  char cc;
  scanf("%d%c", &T, &cc);
  assert(cc == '\n');
  while(T--)
  {
    char prev = 'a'+30;
    char c;
    bool visited[alpha+5] = {0};
    int cnt = 1;
    while(scanf("%c", &c))
    {

      if(c == prev) cnt++;
      else
      {
        if(cnt%2 == 1) visited[int(prev-'a')] = 1;
        prev = c;
        cnt = 1;
      }
      if(c == '\n') break;
    }
    //if(cnt%2 == 1) visited[prev-'a'] = 1;
    for(int i = 0; i < 26; i++) if(visited[i]) printf("%c", 'a'+i);
    cout << endl;
  }


  return 0;
}
