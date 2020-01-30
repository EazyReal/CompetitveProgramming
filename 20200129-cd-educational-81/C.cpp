#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define debug(x) std::cout << #x << ": " << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int T, n;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in", "r", stdin);
    string s, t, z;
    cin >> T;
    //care
    // s = xxxxxxxxa
    // t = aaaaaaaaax
    while(T--)
    {
      cin >> s >> t;
      vector<int> idx[26+2]; ///id['a']
      int l = s.size();
      rep(i, 0, l) idx[s[i]-'a'].pb(i);
      //rep(i, 0, 26) {rep(j, 0, idx[i].size()) cout << idx[i][j] << ' '; cout << endl;}

      int cursor = -1;
      int now[26+2];
      memset(now, 0, sizeof(now));
      int ans = 1;
      rep(i, 0, t.size())
      {
        int c = t[i]-'a';
        if(idx[c].size() == 0) goto nosol;
        //use all of c this round / or no occurece of "any" c is afternow cursor(i.e. last)
        if(now[c] == idx[c].size() || idx[c][idx[c].size()-1] <= cursor ) {memset(now, 0, sizeof(now)); cursor = -1; ans++; /*debug(i);*/}
        //move to the occurece after now cur
        while(idx[c][now[c]] <= cursor) ++now[c];
        cursor = idx[c][now[c]];
        //if(now[c] == idx[c].size()-1) ans++;
        now[c] = now[c]+1;
      }
      cout << ans << endl;
      continue;
      nosol: cout << -1 << endl;
    }
    return 0;
}


/*
aaabce
aaaabceaaabce
6

!?
*/
