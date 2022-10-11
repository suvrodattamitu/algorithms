//https://leetcode.com/problems/binary-tree-right-side-view
class Solution {
public:
    vector<int> res;
    void dfs(TreeNode *root, int level)
    {
        if(root == NULL) 
		    return;
        if(res.size() < level) 
		    res.push_back(root->val);
        dfs(root->right, level+1);
        dfs(root->left, level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) 
    {
        dfs(root, 1);   
        return res;
    }
};