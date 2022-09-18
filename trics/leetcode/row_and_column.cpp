//https://leetcode.com/contest/weekly-contest-303/problems/equal-row-and-column-pairs/
class Solution {
public:    
    int equalPairs(vector<vector<int>>& a) {
        int n = a.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                bool is = true;
                for(int k = 0; k < n; k++) {
                    if(a[i][k] != a[k][j]) {
                        is = false;
                    }
                }
                ans += is;
            }
        }
        return ans;
    }
};
