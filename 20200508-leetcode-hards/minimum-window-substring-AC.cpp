#include <bits/stdc++.h>
using namespace std;

#define ALPHA 100

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        int type = 0;
        int ttype = 0;
        vector<int> cur(ALPHA, 0);
        vector<int> cnt(ALPHA, 0);
        for(int i = 0; i < m; i++) cnt[t[i] - 'A'] ++;
        for(int c = 0; c < ALPHA; c++) if(cnt[c]) type++;
        int l = 0, r = 0;
        while(r < n && ttype < type)
        {
            int id = s[r] - 'A';
            if(cnt[id] == 0) {r++; continue;}
            cur[id]++;
            if(cur[id] == cnt[id]) ttype++, r++;
            else r++;
        }
        if(r == n && ttype < type)
        {
            return "";
        }
        cerr << r << endl;
        //cout << int('a') << int('A') << endl;
        
        int ml = l, mr = r, minv = r-l;
        while(r <= n)
        {
            while(l < r && (cnt[s[l] - 'A'] == 0 || cur[s[l] - 'A'] > cnt[s[l] - 'A']))
            {
                cur[s[l] - 'A']--;
                l++;
            }
            minv = min(minv, r-l);
            if(r-l == minv)
            {
                mr = r, ml = l;
            }
            if(r == n) break;
            int id = s[r] - 'A';
            cur[id] ++;
            r++;
        }
        
        return s.substr(ml, mr-ml);
        
    }
};