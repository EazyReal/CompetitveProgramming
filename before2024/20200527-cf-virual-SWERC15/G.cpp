#include <bits/stdc++.h>

#define rep(i,s,t) for(int i = s; i < t; ++i)
#define ll long long
#define X first 
#define Y second
#define pb push_back

using namespace std;

using pii = pair<int,int>;

const int maxn = 1e2+5;
const int maxmi = 1e3+5;    
int n, k;
int m[maxn];
//vector<vector<int>> G[maxn];
int A[maxn][maxmi];

int calc(int id)
{
    int x = m[id];
    vector<int> sg(x+5, 0);
    rep(i, 0, x)
    {
        vector<bool> S(11, 0); //max mex is not over 10, pig princ
        rep(ki, 0, k+1) //take
        {
            int c = i-ki;
            if(c < 0) continue; // = 0 => first
            int cc = c-A[id][c];
            if(cc < -1) continue; // => cannot take this move
            else if (cc == -1) S[0] = 1; // take all, next stat is with sg[0]
            else S[sg[cc]] = 1; //c is already calc
        }
        //sg[i] = 13;
        rep(sgi, 0, 11) if(S[sgi] == 0) {sg[i] = sgi; break;}
    }
    //assert(sg[0] == 0);
    return sg[x-1]; //len >= 1
}

signed main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  cin >> n >> k;
  rep(i, 0, n)
  {
      cin >> m[i];
      rep(j, 0, m[i]) cin >> A[i][j];
  }
  int SG = 0;
  rep(i, 0, n)
  {
      SG ^= calc(i);
  }
  if(SG == 0) cout << "Bob will win.\n";
  else cout << "Alice can win.\n";

  return 0;
}
