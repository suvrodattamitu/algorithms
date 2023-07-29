//https://leetcode.com/problems/jump-game/description/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define memo(a) memset(a, -1, sizeof(a));
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
    int dp[10005];
    bool rec(int i, vector<int>& nums) {
        if(i >= nums.size()-1) return true;
        if(dp[i] != -1) return dp[i];

        int ans = false;
        for(int jump = 1; jump <= nums[i]; jump++) {
            ans |= rec(i+jump, nums);

            if(ans) { 
                return dp[i] = ans; 
            }
        }

        return dp[i] = ans;
    }

    bool canJump(vector<int>& nums) {
        memo(dp);
        bool ans = rec(0, nums);
        return ans;
    }
};