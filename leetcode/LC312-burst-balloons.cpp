//obserbation : last pick matters => trivial!!
//not "hard" at all :(
#define rep(i, st, n) for (int i = (st); i < (n); ++i)
#define repinv(i, st, n) for (int i = ((n)-1); i >= (st); --i)

class Solution {
public:
    int maxCoins(vector<int>& a) {
        const int n = a.size();
        if(n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0)); //2-d vector init
        repinv(L, 0, n) rep(R, L, n) //technique for iterate from small interval
        {
          rep(i, L, R+1) //last pick among L R
          {
            dp[L][R] = max(dp[L][R], (i-1 < L ? 0 : dp[L][i-1]) +
                                     (i+1 > R ? 0 : dp[i+1][R]) +
                                     (L > 0 ? a[L-1] : 1)  * a[i] * (R+1 < n ? a[R+1] : 1)
                                   );
          }
        }
        return dp[0][n-1];

    }
};
