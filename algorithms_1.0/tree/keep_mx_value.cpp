//https://leetcode.com/problems/count-good-nodes-in-binary-tree

/*
top to bottom solution
*/
class Solution {
public:
    int ans = 0;
    void findGoodNodes(TreeNode* root, int prevMax = -500001) {
        if(!root)              
            return;
        
        if(root->val >= prevMax) {
            ans++;
            prevMax = root->val;
        }
        
        findGoodNodes(root->left, prevMax);
        findGoodNodes(root->right, prevMax);
    }
    
    int goodNodes(TreeNode* root) {
        findGoodNodes(root);
        return ans;
    }
};