#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[2525];
    int lis(int n, vector<int>& nums) {
        if(dp[n] != -1) return dp[n];
        
        int ans = 1;
        for(int i = 0; i < n; i++) {
            if(nums[n] > nums[i]) {
                ans = max(ans, lis(i, nums) + 1);
            }
        }

        return dp[n] = ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int ans = 1;
        for(int i = 0; i < nums.size(); i++) {
            ans = max(ans, lis(i, nums));
        }
        
        return ans;
    }
};