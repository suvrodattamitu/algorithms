//https://leetcode.com/contest/weekly-contest-305/problems/reachable-nodes-with-restrictions/
class Solution {
public:
    int visited[100005], impossible[100005], cnt = 0;
    vector<int> g[100005];
    
    void dfs(int v) {
        visited[v] = 1;
        ++cnt;
        for (int to : g[v]) {
            if (!visited[to] && !impossible[to]) {
                dfs(to);
            }
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        for(int i = 0; i < n-1; i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        
        for(int i = 0; i < 100005; i++) {
            visited[i] = 0;
        }
        
        for(int r : restricted) {
            impossible[r] = 1;
        }
        
        dfs(0);
        
        return cnt;
    }
};