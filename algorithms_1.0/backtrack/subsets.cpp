//https://leetcode.com/problems/subsets/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> all_subsets;
    void rec(int i, vector<int>& nums, vector<int>& subset) {
        if(i  == nums.size()) {
            all_subsets.push_back(subset);
            return;
        }

        //don't take cur element
        rec(i+1, nums, subset);

        //take cur element
        subset.push_back(nums[i]);
        rec(i+1, nums, subset);
        subset.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        rec(0, nums, subset);
        return all_subsets;
    }
};