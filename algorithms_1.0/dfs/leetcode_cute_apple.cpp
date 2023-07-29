//https://leetcode.com/contest/weekly-contest-188/problems/minimum-time-to-collect-all-apples-in-a-tree/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
using namespace std;

class Solution {
public:
    int vis[100005];
    vector<int> adj[100005];
    
    void dfs(int v, vector<bool>& hasApple){
        vis[v] = 1;
        for (int to : adj[v]) {
            if (!vis[to]) {
                dfs(to, hasApple);
                if(hasApple[to]) {
                    hasApple[v] = true;
                }
            }
        }
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for(int i = 0; i < n-1; i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        dfs(0, hasApple);
        
        int ans = -2;
        for(int i = 0; i < n; i++) {
            if(hasApple[i]) ans += 2;
        }
        
        if(ans < 0) ans = 0;
        
        return ans;
    }
};

int main() {
    int n = 4;
    vector<vector<int>> edges = {{0,2},{0,3},{1,2}};
    vector<bool> hasApple = {false, true, false, false};

    Solution obj;
    int ans = obj.minTime(n, edges, hasApple);
    cout << ans << endl;
}