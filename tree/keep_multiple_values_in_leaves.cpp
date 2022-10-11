//https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree

/*
bottom to top solution
*/
class Solution {
public:
    int ans;
    pair<int, int> sumNumbers(TreeNode* root) {
        if(!root)              
            return {0, 0};
            
        auto left  = sumNumbers(root->left);
        auto right = sumNumbers(root->right);
        
        int sum     = root->val + left.first + right.first;
        int child   = left.second + right.second + 1;
        
        if(sum/child == root->val) ans++;
        return {sum, child};
    }
    
    int averageOfSubtree(TreeNode* root) {
        sumNumbers(root);
        return ans;
    }
};