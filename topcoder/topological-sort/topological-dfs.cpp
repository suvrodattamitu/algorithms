//https://community.topcoder.com/stat?c=problem_statement&pm=17626&rd=19234
#include <iostream>
#include <map>
#include <functional>
#include <queue>
#include <vector>
#include <math.h>
#include <algorithm>
#include <complex>
#include <utility>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <iomanip>
#include <fstream>
using namespace std;

#define pb push_back

class LockedBoxes {
    public:
    vector<int> adj[1005];
    int vis[1005];
    vector<int> order;
    
    void topological(int node)
    {
        vis[node] = 1;
        for(auto i: adj[node])
        {
            if(!vis[i])
                topological(i);
        }
        order.pb(node);
    }
    
    void dfs(int node)
    {
        vis[node] = 1;
        for(auto i : adj[node])
        {
            if(!vis[i])
                dfs(i);
        }
    }
    
    vector <int> openAll(int N, vector <int> box, vector <int> key)
    {
        //create adj list
        int box_size = box.size();
        for(int i = 0; i < box_size; i++) {
            int u = box[i];
            int v = key[i];
            
            if(u == v)
                continue;
            adj[u].pb(v);
        }
        
        //make topological order
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < N; i++)
        {
            if(vis[i] == 0)
            {
                topological(i);
            }
        }
        
        reverse(order.begin(), order.end());
        
        //run dfs and find how many elements are unvisited
        memset(vis, 0, sizeof(vis));
        vector<int> ans;
        for(auto i : order)
        {
            if(vis[i] == 0)
            {
                ans.pb(i);
                dfs(i);
            }
        }
        
        return ans;
    }
};

int main() {
  int n;
  vector<int> box, key, arr;
  
  n = 6;
  box = {3, 1, 3, 0, 2, 4, 4};
  key = {4, 3, 5, 1, 0, 4, 3};
  
  LockedBoxes obj;
  arr = obj.openAll(n, box, key);
  
  for(int val : arr) {
      cout << val << " ";
  }
  return 0;
}