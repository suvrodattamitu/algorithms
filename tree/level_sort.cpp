//https://leetcode.com/contest/weekly-contest-319/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> A;
    
    void dfs(TreeNode* root, int d) {
        if (!root) return;
        if (d >= A.size()) A.resize(d+1);
        A[d].push_back(root->val);
        dfs(root->left, d+1);
        dfs(root->right, d + 1);
    }
    
    int f(vector<int> & B) {
        // num swaps needed to get here
        int n = B.size();
        
        vector<int> target = B;
        sort(target.begin(), target.end());
        
        unordered_map<int, int> M;
        for (int i = 0; i < n; i++) {
            M[B[i]] = i;
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = B[i];
            int y = target[i];
            
            if (x == y) continue;
            
            int j = M[target[i]];
            
            swap(B[i], B[j]);
            M[y] = i; M[x] = j;
            
            ans++;
        }
        return ans;
    }
    
    int minimumOperations(TreeNode* root) {
        dfs(root, 0);
        
        int ans = 0;
        for (auto & v : A) {
            ans += f(v);
        }
        return ans;
        
    }
};