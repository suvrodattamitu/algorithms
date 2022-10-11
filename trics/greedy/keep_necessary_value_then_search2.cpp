//https://leetcode.com/problems/find-all-good-indices/
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size(), inc = 1, dec = 1;
        int ans[2][n];
        
        ans[0][0] = (1 == k);
        ans[1][0] = (1 == k);
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1]) {
                inc++;
                dec++;
            } else if(nums[i] > nums[i-1]) {
                inc++;
                ans[0][i] = (inc >= k);
                ans[1][i] = (dec >= k);
                dec = 1;
            } else {
                dec++;
                inc = 1;
            }
            
            ans[0][i] = (inc >= k);
            ans[1][i] = (dec >= k);
        }
        
        vector<int> idx;
        for(int i = k; i + k < n; i++) {
            if(ans[0][i+k] && ans[1][i-1]) {
                idx.push_back(i);
            }
        }
                
        return idx;
    }
};