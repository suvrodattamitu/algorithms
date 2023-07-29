//https://leetcode.com/problems/partition-equal-subset-sum/description/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[205][20005];
    bool rec(int idx, int sum, vector<int>& nums) {
        if(sum == 0) return true;
        if(idx < 0) return false;

        if(dp[idx][sum] != -1) return dp[idx][sum];
        //not consider ith idx
        bool is_possible = rec(idx-1, sum, nums);

        //consider ith idx
        if(sum - nums[idx] >= 0)
            is_possible |= rec(idx-1, sum - nums[idx], nums);

        return dp[idx][sum] = is_possible;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum%2) return false;

        sum /= 2;

        memset(dp, -1, sizeof(dp));

        int n = nums.size();
        return rec(n-1, sum, nums);
    }
};