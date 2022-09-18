//https://leetcode.com/problems/sum-root-to-leaf-numbers/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root, int val = 0) {    // Initially the val would be zero
        if(!root)              // If the root node is itself NULL then return 0;
            return 0;
        val = val * 10 + root->val;     // Add the current nodes val in the number till current
        if(!root->left and !root->right)   //If we reach leaf node add it to the solution
            return val;
        
        int ans = 0;
        ans += sumNumbers(root->left, val) + sumNumbers(root->right, val);   //Similarly recursively call for left and right subtree
        return ans;
    }
};