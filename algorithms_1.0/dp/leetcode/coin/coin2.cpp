//https://leetcode.com/problems/coin-change-ii/description/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define put(n) (cout << n << endl)
#define get(n) (cin >> n)
#define len(x) ((ll)x.size()) 
#define pb push_back
const ll MOD = 1000000007;
const long long oo = 1e16;
const ll MX = (1LL<<60);
const int LOG = 60;
const ll N = 1e5+10;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

class Solution {
public:
    int dp[305][5005];
    int rec(int idx, int amount, vector<int>& coins) {
        if(amount == 0) {
            return 1;
        }

        if(idx < 0) return 0;

        if(dp[idx][amount] != -1) return dp[idx][amount];
        
        int ways = 0;
        for(int coin_amount = 0; coin_amount <= amount; coin_amount += coins[idx]) {
            ways += rec(idx-1, amount - coin_amount, coins);
        }

        return dp[idx][amount] = ways;
    }

    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        int ans = rec(len(coins)-1, amount, coins);
        return ans;
    }
};