//https://leetcode.com/problems/combination-sum-iv/?envType=study-plan-v2&id=dynamic-programming
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1005];
    int rec(vector<int>& nums, int target) {
        if(target < 0) return 0;
        if(target == 0) return 1;

        if(dp[target] != -1) return dp[target];

        int ways = 0;
        for(int i = 0; i < nums.size(); i++){
            if(target-nums[i] >= 0) {
                ways += rec(nums, target-nums[i]);
            }
        }

        return dp[target] = ways;
    }

    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        int ans = rec(nums, target);
        return ans;
    }
};