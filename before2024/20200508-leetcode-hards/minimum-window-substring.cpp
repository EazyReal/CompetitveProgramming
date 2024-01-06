#include <bits/stdc++.h>
using namespace std;

#define ALPHA 100

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        //int type = 0;
        int ttype = 0;
        vector<int> has(ALPHA, 0);
        vector<int> cnt(ALPHA, 0);
        for(int i = 0; i < m; i++) has[t[i] - 'A'] = 1;
        for(int c = 0; c < ALPHA; c++) if(has[c]) type++;
        int l = 0, r = 0;
        while(r < n && ttype < type)
        {
            int id = s[r] - 'A';
            if(!has[id]) {r++; continue;}
            cnt[id]++;
            if(cnt[id] == 1) ttype++, r++;
            else r++;
        }
        if(r == n)
        {
            bool flag = 1;
            //for(int c = 0; c < ALPHA; c++) if(has[c]) type++;
            if(flag) return "";
        }
        cerr << r << endl;
        //cout << int('a') << int('A') << endl;
        
        int ml = l, mr = r, minv = r-l;
        while(r < n)
        {
            int id = s[r] - 'A';
            cnt[id] ++;
            r++;
            while(l < r && (!has[s[l] - 'A'] || cnt[s[l] - 'A'] > 1))
            {
                cnt[s[l] - 'A']--;
                l++;
            }
            minv = min(minv, r-l);
            if(r-l == minv)
            {
                mr = r, ml = l;
            }
        }
        
        return s.substr(ml, mr-ml);
        
    }
};