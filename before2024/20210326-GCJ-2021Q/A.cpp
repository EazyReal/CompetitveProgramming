#include <bits/stdc++.h>
using namespace std;
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define repinv(i, st, n) for (int i = ((n)-1); i >= (st); --i)

int a[105];

void solve()
{
    int n;
    cin >> n;
    //for(int &ai: a) cin >> ai;
    rep(i, 0, n) cin >> a[i];
    int cnt = 0;

    rep(i, 0, n-1)
    {
        // Li is given range
        int k = i;
        rep(j, i+1, n) //naive O(n^2) method
        {
            if(a[j] < a[k])  k = j;
        }
        reverse(a+i, a+k+1);
        cnt += k-i+1;
    }

    cout << cnt << endl;
    return;
}
 
int main()
{
    fastIO();
    int tc;
    cin >> tc;
    for(int T = 1; T <= tc; T++)
    {
        cout << "Case #" << T << ": ";
        solve();
    }
    return 0;
}