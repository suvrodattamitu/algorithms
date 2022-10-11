//https://leetcode.com/problems/longest-nice-subarray/
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size(), cnt = 0, ans = 0;
        vector<int> bits(32, 0);
        
        for(int i = 0; i < n; i++) {            
            for(int j = 0; j < 32; j++) {
                if(nums[i] & (1 << j)) bits[j]++;
            }
            
            int mxBit = *max_element(bits.begin(), bits.end());
            
            //sliding window for valid subarray
            // Increase the window size from left direction.
            while(mxBit > 1 && cnt < i) {
                // Remove all the bits of ith element.
                for(int j = 0; j < 32; j++) {
                    if(nums[cnt] & (1 << j)) bits[j]--;
                }
                cnt++;
                mxBit = *max_element(bits.begin(), bits.end());
            }
            
            // Update the answer with window size which is valid
            ans = max(ans, i - cnt + 1);
        }
        
        return ans;
    }    
};