//https://leetcode.com/problems/maximum-strength-of-a-group/description
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long ans = INT_MIN;
    void solve(vector<int>&nums, int index, long long product, int size) {
        if (index == nums.size()) { 
            if (size != 0) ans = max(ans, product);  //we need a non empty group
            return; 
        }

        solve(nums, index + 1, product * nums[index], size + 1); //pick
        solve(nums, index + 1, product, size); //not pick
    }

    long long maxStrength(vector<int>& nums) {
        solve(nums, 0, 1, 0);
        return ans;
    }
};