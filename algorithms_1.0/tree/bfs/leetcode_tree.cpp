//https://leetcode.com/contest/weekly-contest-307/problems/amount-of-time-for-binary-tree-to-be-infected/
#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <string>
#include <queue>
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
    int vis[100001], cnt = 0;
    void make_adj(TreeNode* t, int p, vector<vector<int>> &adj) {
        if(p != -1) {
            adj[t->val].push_back(p);
        }
        
        if(t->left) {
            adj[t->val].push_back(t->left->val);
            make_adj(t->left, t->val, adj);
        }
        
        if(t->right) {
            adj[t->val].push_back(t->right->val);
            make_adj(t->right, t->val, adj);
        }
    }
    
    int bfs(int start, vector<vector<int>> &adj) {
        queue<pair<int,int>> q;
        vis[start] = true;
        q.emplace(start, 0);
        int ans = 0;
        while(!q.empty()) {
            auto [u, t] = q.front();
            q.pop();
            ans = t;
            for(int v : adj[u]) {
                if(!vis[v]) {
                    vis[v] = true;
                    q.emplace(v, t+1);
                }
            }
        }
        
        return ans;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> adj(100001);
        make_adj(root, -1, adj);
        
        int result = bfs(start, adj);
        
        return result;
    }
};

int main() {

}