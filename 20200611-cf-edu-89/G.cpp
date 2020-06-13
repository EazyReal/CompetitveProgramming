#include <bits/stdc++.h>
using namespace std;

#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int T;
const int maxn = 1e4+7;
int n, m;
string s, t;
int to[maxn]; //the next position after first pre = 0

//check T
void solve()
{
    cin >> s >> t;
    n = s.size(); m = t.size();
    memset(to, -1, sizeof(to));
    rep(i, 0, n)if(s[i] != '.')
    {
        int pre = 0;
        to[i] = -1;
        rep(j, i, n)
        {
            pre += s[j] == '.' ? -1 : 1;
            if(pre == 0) { to[i] = j; break;}
        }
    }
    int INF = 101010;
    vector<vector<int>> dp(n+1, vector<int>(m+1, INF));
    dp[0][0] = 0;
    rep(i, 0, n)rep(j, 0, m+1)  
    {
        dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);  
        if(j < m && s[i] == t[j]) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
        if(s[i] != '.' && to[i] != -1) dp[to[i]+1][j] = min(dp[to[i]+1][j], dp[i][j]);
    }
    cout << dp[n][m] << endl;
    return;
}

signed main()
{
    fastIO();
    solve();
    return 0;
}
