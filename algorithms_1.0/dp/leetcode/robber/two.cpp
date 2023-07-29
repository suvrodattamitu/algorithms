//https://leetcode.com/problems/house-robber-ii/description
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
    int rec(int ind, int n, vector<int> &nums, vector<int> &dp)
    {
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + rec(ind+2, n, nums, dp);
        int notPick = rec(ind+1, n, nums, dp);
        return dp[ind] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> dp1(n+1, -1);
        int a = rec(0, n-1, nums, dp1);

        vector<int> dp2(n+1, -1);
        int b = rec(1, n, nums, dp2);
        
        return max(a, b);
    }
};