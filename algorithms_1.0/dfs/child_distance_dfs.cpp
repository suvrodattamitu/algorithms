//https://leetcode.com/problems/sum-of-distances-in-tree/description/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef vector<int> vi;
typedef vector<vector<int> > vii;

class Solution {
public:
    vii graph;
    vi dis, child, sum;
    
    int total;
    void dfs2(int u, int p = -1) {
        for(int v : graph[u]) {
            if(v == p) continue;
            sum[v] = sum[u] - child[v] + (total-child[v]);
            dfs2(v, u);
        }
    }

    void dfs(int u, int p = -1) {
        child[u] = 1;
        for(int v : graph[u]) {
            if(v == p) continue;
            dis[v] = dis[u] + 1;// distance of a node
            dfs(v, u);
            child[u] += child[v];// child of a parent
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        total = n;

        graph.resize(n+1), dis.resize(n+1, 0), child.resize(n+1, 0);
        for(auto edge : edges) {
            int x = edge[0], y = edge[1];
            graph[x].pb(y);
            graph[y].pb(x);
        }

        dfs(0);

        sum.resize(n, 0);
        for(int i = 0; i < n; i++) {
            sum[0] += dis[i];
        }

        dfs2(0);

        return sum;
    }
};