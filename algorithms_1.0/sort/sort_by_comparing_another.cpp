//https://leetcode.com/problems/merge-triplets-to-form-target-triplet/
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        partition(triplets.begin(), triplets.end(), [&target](const auto& v) {
            return v[0] <= target[0] and v[1] <= target[1] and v[2] <= target[2];
        });
        
        int p = 0, q = 0, r = 0;
        for(auto x : triplets) {
            p = max(p, x[0]);
            q = max(q, x[1]);
            r = max(r, x[2]); 

            if(p == target[0] && q == target[1] && r == target[2]) return true;
        }
        
        return false;
    }
};