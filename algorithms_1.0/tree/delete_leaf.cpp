//https://leetcode.com/problems/delete-leaves-with-a-given-value
class Solution {
public:
    TreeNode* removeLeaf(TreeNode* root, int target) {
        if(!root) return NULL;
        root->left  = removeLeaf(root->left, target);
        root->right = removeLeaf(root->right, target);
        if(!root->left && !root->right && root->val == target) return NULL;
        return root;
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return removeLeaf(root, target);
    }
};