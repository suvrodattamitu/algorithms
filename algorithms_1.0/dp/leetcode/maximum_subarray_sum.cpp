//https://leetcode.com/problems/maximum-subarray/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rec(vector<vector<int>>&dp,vector<int>& nums,int idx,bool takeit)
    {
        if(idx >= nums.size())
        {
            return takeit ? 0 : -1e9;
        }

        if(dp[idx][takeit] != -1)
        {
            return dp[idx][takeit];
        }

        //if taken a value previosuly, either return with that value, or take curr value again and recurse
        if(takeit)
        {
            return dp[idx][takeit] = max(0, nums[idx] + rec(dp,nums,idx+1,true));
        }

        //if not taken any value before, take currvalue and recurse or not take curr value and recurse
        return dp[idx][takeit] = max(nums[idx]+rec(dp,nums,idx+1,true) , rec(dp,nums,idx+1,false));
    }

    int maxSubArray(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(2,-1));
        return rec(dp,nums,0,false);
    }
};