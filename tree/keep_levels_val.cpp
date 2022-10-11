//https://leetcode.com/problems/even-odd-tree
class Solution {
public:
    vector<int> v[1000];
    int mxLevel = 0;
    void buildLevels(TreeNode* root, int level = 0) {
        if(!root) return;
        
        mxLevel = max(level, mxLevel);
        
        v[level].push_back(root->val);
        
        buildLevels(root->left,  level+1);
        buildLevels(root->right, level+1);
    }
    
    bool isEvenOddTree(TreeNode* root) {
        buildLevels(root);
        
        bool ok = true;
        for(int i = 0; i <= mxLevel; i++) {
            //even indexed level, a.values should be in increasing order and b. odd
            if(i%2 == 0) {
                int prev = INT_MIN;
                for(int x : v[i]) {
                    if(x <= prev || (x % 2 == 0)) {
                        ok = false;
                        break;
                    }
                    prev = x;
                }
            }
            
            //odd indexed level, values should be in decreasing order and even
            else {
                int prev = INT_MAX;
                for(int x : v[i]) {
                    if(x >= prev || (x%2 == 1)) {
                        ok = false;
                        break;
                    }
                    prev = x;
                }
            }            
        }
        
        return ok;
    }
};