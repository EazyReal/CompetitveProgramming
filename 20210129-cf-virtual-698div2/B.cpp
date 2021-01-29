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
    vector<int> thre(10, 2e9);
    rep(i, 1, 11)
    {
        //cerr << "debug\n";
        int ins = d*i;
        thre[ins%10] = min(thre[ins%10], ins);
    }
    rep(i, 0, n)
    {
        //err << "debug\n";
        cin >> a;
        if(a >= thre[a%10] || a >= d*11) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    //cerr << "debug\n";
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
