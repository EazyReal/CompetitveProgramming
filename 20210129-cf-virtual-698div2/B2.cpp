#include <bits/stdc++.h>
using namespace std;
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
//------------------------------------------------------------------------//
int T;
const int maxn = 2e5+7;
int n, d;
int a;

//check T
void solve()
{
    cin >> n >> d;
    int thre = 10*d+9; // a = 10d+(desired k) + d + d + ...
    vector<int> dp(10*d+9+1, 0); //under thre use dp to solve 
    dp[0] = 1;
    auto can = [] (int delta)
    {
        return (delta%10 == d) || (delta/10==d);
    };
    rep(i, 0, thre) rep(j, 0, i)
    {
        if(can(i-j)) dp[i] |= dp[j];
    }
    rep(i, 0, n)
    {
        cin >> a;
        if(a >= thre || dp[a]) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return;
}


//g++ -o out -std=c++11 A.cpp

signed main()
{
    fastIO();
    cin >> T; 
    rep(tc, 1, T+1)
    {
        solve();
    }
    return 0;
}
