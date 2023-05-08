//https://leetcode.com/problems/coin-change-ii/description/?envType=study-plan-v2&id=dynamic-programming
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[305][5005];
    int rec(int idx, int amount, vector<int>& coins) {
        if(idx == 0) {
            return (amount % coins[idx] == 0);
        }

        if(dp[idx][amount] != -1){
            return dp[idx][amount];
        }

        //not take
        int not_take = rec(idx - 1, amount, coins);
        
        //take
        int take = 0;
        if(amount - coins[idx] >= 0) { 
            take = rec(idx, amount - coins[idx], coins);
        }

        return dp[idx][amount] = not_take + take;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size()-1;
        memset(dp, -1, sizeof(dp));
        int ans = rec(n, amount, coins);
        return ans;
    }
};