//https://leetcode.com/contest/weekly-contest-313/problems/maximum-sum-of-an-hourglass/
class Solution {
public:
    int maxSum(vector<vector<int>>& a) {
        int row = a.size(), columns = a[0].size();
        int ans = 0;
        for(int i = 0;i < row-2;i++){
            for(int j = 0;j < columns-2;j++){
                int s = a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j+1] + a[i+2][j] + a[i+2][j+1] + a[i+2][j+2];
                ans = max(ans, s);
            }
        }
        
        return ans;
    }
};