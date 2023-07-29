//https://leetcode.com/problems/house-robber/description/
#include <bits/stdc++.h>
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
    int solve(vector<int> &nums, int ind,vector<int> &dp)
    {
        if(ind >= nums.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + solve(nums, ind+2, dp);
        int notPick = solve(nums, ind+1, dp);
        return dp[ind] = max(pick, notPick);
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(nums, 0, dp);
    }
};