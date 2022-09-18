//https://leetcode.com/contest/biweekly-contest-81/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
class Solution {
public:
    void dfs(int v, vector<int> &vis, vector<int> Adj[], int &c) {
        if(vis[v] == 1) return;

        vis[v] = 1;
        c++;

        for(auto u: Adj[v]) {
            if(!vis[u]) {
                dfs(u, vis, Adj, c);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
            vector<int> vis(n, 0);
            vector<int> adj[n];
        
            for(auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            

            long long ans=0;
            for(int i = 0; i < n; i++) {
                if(vis[i] != 1) {
                    int c=0;
                    dfs(i, vis, adj, c);
                    ans+=1LL*c*(n-c);
                }
            }
                
            return ans/2;
        
    }
};