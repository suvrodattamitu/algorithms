//https://leetcode.com/problems/count-the-number-of-complete-components/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int vis[55];
    vector<vector<int>> graph;
    vector<int> v;
    int cnt;
    void dfs(int u, vector<vector<int>>& graph) {
        vis[u] = 1; 
        v.push_back(u);
        for(auto v : graph[u]) {
            if(!vis[v]) {
                dfs(v, graph);
            }
        }
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        graph.resize(n+1);
        for(auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
               cnt = 0;
               dfs(i, graph);

               int x = v.size();
               int found = 0;
               for(int cur : v) {
                   if(graph[cur].size() != x-1) {
                       found = 1;
                   }
               }

               if(!found) ++ans;
               v.clear();
            }
        }
        
        return ans;
    }
};