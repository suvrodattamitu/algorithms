//https://leetcode.com/contest/biweekly-contest-105/problems/maximum-strength-of-a-group/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long ans = nums[0];
        int n = nums.size();
        for(int mask = 1; mask < (1<<n); mask++){
            long long prod = 1;
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) prod *= nums[i];
            }
            
            ans = max(prod , ans);
        }
        return ans;
    }
};