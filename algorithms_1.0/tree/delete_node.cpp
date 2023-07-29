//https://leetcode.com/problems/delete-node-in-a-bst/description/
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return NULL;
        if(key < root->val)
            root->left = deleteNode(root->left, key);
        else if(key > root->val)
            root->right = deleteNode(root->right, key);
        else
        {
            if(!root->left && !root->right)
                return NULL;
            if(!root->left || !root->right)
            {
                if(root->left)
                    return root->left;
                return root->right;
            }
            else
            {
                TreeNode* t = root->left;
                while(t->right)
                    t = t->right;
                root->val = t->val;
                root->left = deleteNode(root->left, t->val);
            }
        }
        return root;
    }
};