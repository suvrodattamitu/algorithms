//https://leetcode.com/contest/weekly-contest-316/problems/minimum-cost-to-make-array-equal/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long f(vector<int>& nums, vector<int>& costs, int k) {
        long long cost = 0;
        for(int i = 0; i < costs.size(); i++) {
            cost += (abs(nums[i] - k) * 1LL * costs[i]);
        }
        
        return cost;
    }
    
    long long minCost(vector<int>& nums, vector<int>& costs) {
        int mx = *max_element(nums.begin(), nums.end());
                
        int low = 0, high = 1000000, ans = INT_MAX;
        while(low <= high) {
            int mid = (low+high) / 2;
            if(f(nums, costs, mid) < f(nums, costs, mid+1)) {
                high = mid - 1; 
                ans = mid;
            } else {
                low = mid+1; 
            }
        }
        
        return f(nums, costs, ans);
    }
};