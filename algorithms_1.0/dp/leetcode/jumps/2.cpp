//https://leetcode.com/problems/jump-game-ii/description/
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
    int rec(int i, vector<int>& nums) {
        if(i >= nums.size()-1) return 0;
        if(dp[i] != -1) return dp[i];

        int ans = 99999;
        for(int jump = 1; jump <= nums[i]; jump++) {
            ans = min(ans, 1 + rec(i+jump, nums));
        }
 
        return dp[i] = ans;
    }

    int jump(vector<int>& nums) {
        memo(dp);
        int ans = rec(0, nums);
        return ans;
    }
};