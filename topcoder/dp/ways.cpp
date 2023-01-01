//https://arena.topcoder.com/#/u/practiceCode/19427/311155/17858/1/337501
//https://community.topcoder.com/tc?module=ProblemDetail&rd=19426&pm=17858
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long

int N, totalGuests;
class PerfectParty{
    long long dp[60][60][60];
    vector<int> candiess;
    public:
    ll countWays(int idx, int numGuests, int sum) {
        if(numGuests < 0) {
            return 0;
        }
        
        if(idx >= N) {
          if(sum == 0 && numGuests == 0) {
            return 1;
          }
          return 0;
        }
        
        if(dp[idx][numGuests][sum] != -1) {
            return dp[idx][numGuests][sum];
        }
        
        ll ans = 0;
        ans = countWays(idx+1, numGuests , sum) + countWays(idx+1, numGuests-1, (sum + candiess[idx]) % totalGuests);
        
        return dp[idx][numGuests][sum] = ans;
    }
    
    ll invite(vector<int> candies) {
        N = candies.size();
        candiess = candies;
        
        ll ans = 0;
        for(int i = 0; i <= N; i++) {
            memset(dp, -1, sizeof dp);
            totalGuests = i+1;
            ll tmp = countWays(0, i, 0);       
            ans += tmp;
        }
        
        return ans;
    }
};

/*
3 4

1 2 3
2 3 4
1 3 4
1 2 4

then we get just 1 seq
3 3
1 2 3

3 4
2 3 4
1 3 4
1 2 4
*/