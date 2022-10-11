//https://leetcode.com/problems/all-paths-from-source-to-target/
class Solution {
public:
    vector<vector<int>> adj;
    vector<vector<int>> ans;
    
    //dfs find all routes
    void dfs(int source, int destination, int parent, vector<int> cur_route_src) {        
        cur_route_src.push_back(source);  
        if(source == destination) {
            ans.push_back(cur_route_src);
            cur_route_src.clear();
        }
                
        for(int child : adj[source]) {
            if(child != parent)
                dfs(child, destination, source, cur_route_src);  
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int cnt = 0;
        adj = graph;
        
        vector<int> val;
        dfs(0, graph.size()-1, 0, val);
        return ans;
    }
};