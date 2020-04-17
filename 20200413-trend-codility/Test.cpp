// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    vector<bool> occ(n+5, 0);
    for(int &ai: A) if(1 <= ai && ai <= n) occ[ai] = 1;
    int ans = n+1;
    for(int i = 1; i <= n; i++) if(occ[i] == 0){
        ans = i;
        break;
    }
    return ans;
}
