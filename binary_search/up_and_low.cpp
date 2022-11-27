//https://leetcode.com/contest/weekly-contest-320/problems/closest-nodes-queries-in-a-binary-search-tree/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arr;
    
    void treeTraverse(TreeNode* root) {
        if(!root)              
            return;
        
        arr.push_back(root->val);
        
        treeTraverse(root->left);
        treeTraverse(root->right);
    }
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        treeTraverse(root);
        
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> answers;
        for(int q : queries) {
            int upIdx = upper_bound(arr.begin(), arr.end(), q) - arr.begin();
            int lwIdx = lower_bound(arr.begin(), arr.end(), q) - arr.begin();
            
            int mx = -1, mn = -1;
            if(upIdx != 0) {
                mx = arr[upIdx-1];
            } 
                        
            if(lwIdx != arr.size()) {
                mn = arr[lwIdx];
            }
            answers.push_back({mx, mn});
        }
        
        return answers;
    }
};