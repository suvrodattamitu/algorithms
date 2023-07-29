//https://leetcode.com/contest/weekly-contest-305/problems/check-if-there-is-a-valid-partition-for-the-array/
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n+1);
        
        dp[0] = 1;
        for(int i = 0; i < n; ++i) {
            if(dp[i]) {
                if(i+1 < n && nums[i] == nums[i+1]) dp[i+2] = 1;
                if(i+2 < n && nums[i] == nums[i+1] && nums[i] == nums[i+2]) dp[i+3] = 1;
                if(i+2 < n && nums[i]+1 == nums[i+1] && nums[i]+2 == nums[i+2]) dp[i+3] = 1;
            }
        }
        return dp[n];
    }
};

/*

class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26,0);
        for(char c : s) {
            int x = c - 'a';
            dp[x] = max(dp[max(0, x-k)], dp[min(25, x+k)]) + 1;
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
*/