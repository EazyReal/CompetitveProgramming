// you can use includes, for example:
// #include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S)
{
    // write your code in C++ (C++14 (g++ 6.2.0))
    int n = S.length();
    int pre = 0;
    int best = 0;
    unordered_map<int, int> last;
    last[0] = -1;
    for (int i = 0; i < n; ++i)
    {
        pre ^= 1 << int(S[i] - 'a');
        if (last.find(pre) == last.end())
            last[pre] = i;
        else
            best = max(best, i - last[pre]);
        if (best == i - last[pre])
            cout << S.substr(last[pre] + 1, i - last[pre]) << endl;
    }
    return best;
}

int main()
{
    string S;
    cin >> S;
    cout << solution(S) << endl;
    return 0;
}