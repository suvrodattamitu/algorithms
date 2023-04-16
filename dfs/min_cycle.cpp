//https://leetcode.com/problems/shortest-cycle-in-a-graph/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = INT_MAX;
    void dfs(vector<int>adj[],vector<int>&vis,int ind,int len,int par,vector<int>&dis){
        if(dis[ind]) return;

        vis[ind] = 1;
        dis[ind] = len;
        for(auto it : adj[ind]){
            if(it == par) continue;
            if(vis[it]) {
                ans = min(ans,len-dis[it]+1);
                continue;
            }
            dfs(adj,vis,it,len+1,ind,dis);
        }
        vis[ind] = 0;
    }
    
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        vector<int>dis(n,0);

        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            vector<int>dis(n,0);
            dfs(adj,vis,i,1,-1,dis);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

// #define rep(i, n) for (int i=0; i<n; i++)

// class Solution {
// public:
//     int findShortestCycle(int n, vector<vector<int>>& edges) {
//         vector<int> G[n];
//         for (int i=0; i<edges.size(); i++) {
//             int u = edges[i][0];
//             int v = edges[i][1];
//             G[u].push_back(v);
//             G[v].push_back(u);
//         }
//         int res = 100000;
//         rep(i, n) {
//             vector<int> dist(n, -1);
//             vector<int> par(n, -1);
//             dist[i] = 0;
//             queue<int> q;
//             q.push(i);
//             while (q.size()) {
//                 int v = q.front(); q.pop();
//                 rep(j, G[v].size()) {
//                     int nv = G[v][j];
//                     if (dist[nv]==-1) {
//                         dist[nv] = dist[v]+1;
//                         q.push(nv);
//                         par[nv] = v;
//                     }
//                     else if (par[nv]!=v && par[v]!=nv) {
//                         res = min(res, dist[v]+dist[nv]+1);
//                     }
//                 }
//             }
//         }
//         if (res==100000) return -1;
//         return res;
//     }
// };
