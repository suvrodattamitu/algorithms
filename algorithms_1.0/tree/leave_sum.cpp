//https://leetcode.com/problems/sum-root-to-leaf-numbers
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