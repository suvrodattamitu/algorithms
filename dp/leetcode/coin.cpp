//https://leetcode.com/problems/coin-change
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[10009];
    int rec(int amount, vector<int>& coins) {
        if(amount == 0) return 0;
        
        if(dp[amount] != -1) return dp[amount];
        
        int ans = INT_MAX;
        for(int coin : coins) {
            if(amount-coin >= 0) {
                ans = min(ans+0ll, rec(amount-coin, coins)+1ll);
            }
        }
        
        return dp[amount] = ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = rec(amount, coins);
        if(ans == INT_MAX) ans = -1;
        return ans;
    }
};