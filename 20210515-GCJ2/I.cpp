#include <bits/stdc++.h>
using namespace std;

#define rep(i, st, n) for (int i = (st); i < (n); ++i)

int T, N;
//g++ -o out -std=c++11 A.cpp

signed main()
{
    cin >> T >> N; //this
    rep(tc, 1, T+1)
    {
        rep(i, 1, N)
        {
            int x;
            cout << "M " << i << " " << N << endl << flush;
            cin >> x;
            if(x != i)
            {
                cout << "S " << i << " " << x << endl << flush;
                cin >> x; assert(x==1);
            }
        }
        cout << "D" << endl << flush;
        int x; 
        cin >> x; assert(x==1);
    }
    return 0;
}
