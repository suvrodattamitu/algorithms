//https://leetcode.com/contest/biweekly-contest-102/problems/cousins-in-binary-tree-ii/
#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<TreeNode*, long long> childSum;
    unordered_map<int, long long> levelSum;
    void dfs1(TreeNode* root, TreeNode* parent, int level) {
        if (root == NULL) {
            return;
        }
        
        levelSum[level] += root->val;
        childSum[parent] += root->val;
        
        dfs1(root->left, root, level+1);
        dfs1(root->right, root, level+1);
    }
    
    void dfs2(TreeNode* root, TreeNode* parent, int level) {
        if (root == NULL) {
            return;
        }
        
        root->val = levelSum[level] - childSum[parent];
        
        dfs2(root->left, root, level+1);
        dfs2(root->right, root, level+1);
    }
    
    TreeNode* replaceValueInTree(TreeNode* root) {
        dfs1(root, NULL, 0);
        dfs2(root, NULL, 0);
        
        return root;
    }
};