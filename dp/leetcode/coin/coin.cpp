//https://leetcode.com/problems/coin-change
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
    ll dp[N];
    ll rec(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        
        if(dp[amount] != -1) return dp[amount];
        
        ll ans = oo;
        for(int coin : coins) {
            if(amount-coin >= 0) {
                ans = min(ans, 1 + rec(coins, amount-coin));
            }
        }  
        
        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));

        ll ans = rec(coins, amount);
    
        if(ans == oo) ans = -1;
        return (int)ans;
    }
};