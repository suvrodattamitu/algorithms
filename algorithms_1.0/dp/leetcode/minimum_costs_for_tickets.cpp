//https://leetcode.com/problems/minimum-cost-for-tickets/description
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[400];
    int rec(int idx, int validity, vector<int>& days, vector<int>& costs) {
        // if we reach last index
        if(idx >= days.size()) return 0;

        // if we buy a ticket with validity greater than current day
        if(validity >= days[idx]) return rec(idx+1, validity, days, costs);

        // if we have already came across day[index], we can return dp[index] which has the minimum cost
        if(dp[idx] != -1) return dp[idx];

        int mn = INT_MAX;

        // Taking 1 day ticket and adding cost to present cost
        mn = min(mn, costs[0] + rec(idx+1, days[idx], days, costs));

        // Taking 7 day ticket and adding cost to present cost
        mn = min(mn, costs[1] + rec(idx+1, days[idx] + 6, days, costs));

        // Taking 30 day ticket and adding cost to present cost
        mn = min(mn, costs[2] + rec(idx+1, days[idx] + 29, days, costs));

        return dp[idx] = mn;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));

        int ans = rec(0, 0, days, costs);
        return ans;
    }
};