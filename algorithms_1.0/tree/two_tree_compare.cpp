//https://leetcode.com/problems/same-tree/description/
#include<bits/stdc++.h>
using namespace std;

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return 1;
        if(p == NULL && q != NULL) return 0;
        if(p != NULL && q == NULL) return 0;

        bool ans = true;
        if(p->val == q->val) {
            ans &= isSameTree(p->left, q->left);
            ans &= isSameTree(p->right, q->right);
        } else {
            return 0;
        }
        return ans;
    }
};