//https://leetcode.com/problems/greatest-common-divisor-traversal/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:    
    // maximum value in nums
    int maxi = 0;

    //generate adjacency list in O(nlogn)
    void gets(vector<int>&pres, vector<vector<int>>&adj) {
        for(int i = 2; i<= maxi; i++){
            for(int j = 2; j*i <= maxi; j++) {
                if(pres[i*j]==0) continue;
                adj[i].push_back(i*j);
                adj[i*j].push_back(i);
            }
        }
    }

    // normal dfs
    void dfs(int ind,vector<int>&vis , vector<vector<int>>&adj) {
        vis[ind] = 1;

        for(auto it: adj[ind]) {
            if(!vis[it]) {
                dfs(it, vis, adj);
            }
        }
    }
    
    bool canTraverseAllPairs(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        vector<int>pres(100005, 0); // marks all numbers in nums[i] = 1 ;
        
        //loop to find out if there are any 1 , mark all elements in pres array and find maximum element
        int one = 0;
        for(int i = 0; i < nums.size(); i++) {
            pres[nums[i]] = 1;
            maxi = max(maxi, nums[i]);
            if(nums[i] == 1) one = 1;
        }
        
        // using maximum element vaue to declare adjacency list size
        vector<vector<int>>adj(maxi+1);
        
        // generating adjacency list
        gets(pres, adj);
        
        // return false if there is any 1 in array
        if(one) return false;
        
        vector<int>vis(maxi+1, 0);
        
        // number of connected components 
        // all the numbers having common factor greater then 1 are in one connected component
        //dfs call // if there are multiple connected components it means that numbers in those different components 
        ///////////// do not have a a common factor greater than 1 which means traversal is not possible
        int cc = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(!vis[nums[i]]) {
                if(cc) return 0;
                dfs(nums[i], vis, adj);
                cc++;
            }
        }        
        
        return 1;        
    }
};