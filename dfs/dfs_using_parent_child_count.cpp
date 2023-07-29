//https://leetcode.com/contest/weekly-contest-320/problems/minimum-fuel-cost-to-report-to-the-capital/
//https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/solutions/3174979/c-dfs-beats-63/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> graph[100005], arr;
    int sub[100005];
    
    //child of each parent count
    void dfs(int u, int p) {
        sub[u] = 1;
        for(auto&x : graph[u]) {
            arr.push_back(x);
            if(x == p) {
                for(int val : arr) {
                    cout << val << endl;
                    arr.clear();
                }
                continue;
            }
            dfs(x, u);
            sub[u] += sub[x];
        }
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        for(auto x : roads) {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        
        dfs(0, -1);
        
        long long ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += (sub[i] / seats) + ((sub[i] % seats) > 0);
        }
                
        return ans;
    }
};