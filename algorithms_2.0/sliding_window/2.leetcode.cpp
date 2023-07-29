//https://leetcode.com/problems/minimum-size-subarray-sum/description/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long long ans = INT_MAX, j = 0, sum = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum >= target) {
                while(sum - nums[j] >= target && j < i) {
                    sum -= nums[j];
                    j++;
                }
                
                ans = min(ans, i - j + 1);
            }
        }

        if(ans == INT_MAX) ans = 0;

        return ans;
    }
};