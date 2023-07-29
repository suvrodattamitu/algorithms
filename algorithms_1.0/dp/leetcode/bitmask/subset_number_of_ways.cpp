//https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/description/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1e9+7;
    int dp[1<<10][41];
    int allMask;
    vector<int> caplist[41];
    
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
       
        allMask = (1 << n) - 1;
        
        //create a cap list , cap -> peoples wearing them    
        for(int i = 0; i < hats.size(); i++) {
            for(int cap : hats[i]) {
                caplist[cap].push_back(i);
            }
        }
           
        memset(dp, -1, sizeof dp);
        
        return capUtil(0, 1);
    }
    
    int capUtil(int mask, int cap) {
        //when all people ware caps
        if(mask == allMask) return 1;
        
        //all caps done 
        if(cap > 40) return 0;
        
        //return ans if precomputed
        if(dp[mask][cap] != -1) return dp[mask][cap];
        
        //when we don't include this cap
        int ways = capUtil(mask, cap+1);
        
        // for all the persons who can ware this cap
        for(int person : caplist[cap]) {
            //he already ware cap
            if(mask & (1 << person)) continue;
            
            ways += capUtil(mask | (1 << person), cap+1);
            
            ways %= MOD;
        }
        
        return dp[mask][cap] = ways;
    }
};