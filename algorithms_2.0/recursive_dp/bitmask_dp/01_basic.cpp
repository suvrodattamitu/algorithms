//https://leetcode.com/problems/subsets/description/
class Solution {
public:
    //solving using bitmasks
    vector<vector<int>> subsets(vector<int>& nums) {
        int size=nums.size();
        vector<vector<int>> sub_set(1<<size); //1<<size=2^size ==> total number of subsets

        for(int i=0; i<(1<<size); i++)       //iterating through each subset
        {
            for(int j=0; j<size; j++)           //iterating throuch each bit of each interger represnting a number in binary;
            {
                if((i>>j)&1)sub_set[i].push_back(nums[j]);    // if the bit is true then put that number in that subet
            }
        }
        return sub_set;
    }
};