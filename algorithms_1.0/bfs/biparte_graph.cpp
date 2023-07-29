//https://leetcode.com/problems/is-graph-bipartite/description/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int color[110];

    bool bfs(int src, vector<vector<int>>& graph) {
        queue<int> q;

        q.push(src);
        color[src] = -1;

        while(!q.empty()) {
            src = q.front();
            q.pop();

            for(auto v : graph[src]) {
                if(!color[v]) {
                    q.push(v);
                    color[v] = -1*color[src];
                }

                //if src and cur node both has same color
                else if(color[v] == color[src]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        bool ans = true;
        for(int i = 0; i < n; i++) {
            if(!color[i]){
                ans &= bfs(i, graph);
                if(!ans) return false;
            }
        }
        
        return ans;
    }
};