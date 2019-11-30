class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int globalmin = abs(nums[0]+nums[1]+nums[2]-target);
        int ret = nums[0]+nums[1]+nums[2];
        int n = nums.size();
        for(int i = 0; i < n-2; i++)
        {
            int l = i+1;
            int r = n-1;
            int cur = nums[i] + nums[l] + nums[r];
            int curret = cur;
            int curmin = abs(cur-target);
            while(l<r)
            {
                if(cur < target) l++;
                else if(cur > target) r--;
                else if(cur == target) return target;
                if(l<r)
                {
                    cur = nums[i] + nums[l] + nums[r];
                    curret = (abs(cur-target)<curmin)?cur:curret;
                    curmin = min(curmin, abs(cur-target));
                }
            }
            ret = (curmin<globalmin)?curret:ret;
            globalmin = min(globalmin, curmin);
        }
        return ret;
    }
};

/*
yt lin 2019.11.30 10:20

https://leetcode.com/problems/3sum-closest/

Success
Details 
Runtime: 8 ms, faster than 80.90% of C++ online submissions for 3Sum Closest.
Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for 3Sum Closest.
*/