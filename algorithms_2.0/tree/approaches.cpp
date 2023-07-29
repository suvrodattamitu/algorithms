//https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
#include <bits/stdc++.h>
using namespace std;

//USING BFS
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int ans = -1, level = 0, mx = INT_MIN;
        while(!q.empty()) {
            ++level;
            
            int sum = 0, sz = q.size();
            for(int i = 0; i < sz; i++) {
                TreeNode* tp = q.front();
                q.pop();
                
                sum += tp->val;

                if(tp->left) q.push(tp->left);
                if(tp->right) q.push(tp->right);
            }

            if(sum > mx) {
                mx = sum;
                ans = level;
            }
        }

        return ans;
    }
};

//USING MY DFS APPROACHE
class Solution {
public:
    map<int, int> sum;
    void rec(TreeNode* root, int level = 0) {
        if(root == NULL) return;
    
        sum[level] += root->val;

        rec(root->left, level+1);
        rec(root->right, level+1);
    }

    int maxLevelSum(TreeNode* root) {
        rec(root);

        int ans = -1, mx = INT_MIN;
        for(auto it : sum) {
            if(it.second > mx) {
                mx = it.second;
                ans = it.first;
            }
        }
        
        return ans+1;
    }
};