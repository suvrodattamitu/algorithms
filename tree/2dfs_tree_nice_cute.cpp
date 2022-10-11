//https://leetcode.com/contest/weekly-contest-311/problems/reverse-odd-levels-of-binary-tree/
class Solution {
public:
    vector<int> v[30];
    void dfs1(TreeNode* root, int level = 0) {
        if(!root) {
            return;
        }
        if(level%2) {
            v[level].push_back(root->val);
        }
        dfs1(root->left, level+1);
        dfs1(root->right, level+1);
    }
    
    void dfs2(TreeNode* root, int level = 0) {
        if(!root) {
            return;
        }
        if(level%2) {
            root->val = v[level].back();
            v[level].pop_back();
        }
        dfs2(root->left, level+1);
        dfs2(root->right, level+1);
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs1(root);
        dfs2(root);
        
        return root;
    }
};