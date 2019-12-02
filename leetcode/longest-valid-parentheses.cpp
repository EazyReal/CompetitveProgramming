class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int sum = 0;
        int ret = 0;
        int l, r;
        for(l = 0, r = 0; r < n; r++)
        {
            //cout << sum;
            if(s[r] == '(') sum++;
            else if (s[r] == ')') sum--;
            if(sum == 0 && s[r]== ')') ret = max(ret, r-l+1);
            while(sum < 0 && l <= r) sum += (s[l++]=='(')?-1:1;
            //r = max(r, l-1);
        }
        sum = 0;
        for(l = n-1, r = n-1; l >= 0; l--)
        {
            if(s[l] == ')') sum++;
            else if (s[l] == '(') sum--;
            if(sum == 0 && s[l] == '(') ret = max(ret, r-l+1);
            while(sum < 0 && r >= l) sum += (s[r--]==')')?-1:1;
            //l = min(r+1, l);
        }
        return ret;
    }
};

/*
https://leetcode.com/problems/longest-valid-parentheses/

Success
Details 
Runtime: 4 ms, faster than 96.22% of C++ online submissions for Longest Valid Parentheses.
Memory Usage: 9.1 MB, less than 96.43% of C++ online submissions for Longest Valid Parentheses.
*/