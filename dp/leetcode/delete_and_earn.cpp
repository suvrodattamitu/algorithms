//https://leetcode.com/problems/delete-and-earn/description/
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
    int dp[2*10005];
    int rec(int i, vector<int>& nums) {
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        
        // current 'i' on which we are standing
        int currValue = nums[i];  // current value
        int currSum = nums[i]; // intial make sum as same as value
        int index = i + 1; // index to take elemets, so  i + 1
        
        // while it is the same as the current value, include in our sum
        while(index < nums.size() && nums[index] == currValue) {
            currSum += nums[i];
            index++;
        }
        
        // Now, we have to skip all the elements, whose value is equal to
        // currValue + 1
        while(index < nums.size() && nums[index] == currValue + 1) {
            index++;
        }

        // whether to include the sum of this current element in our answer
        // or not include the sum of current element in our answer
        return dp[i] = max(currSum + rec(index, nums), rec(i+1, nums));
    }

    int deleteAndEarn(vector<int>& nums) {
        memo(dp);
        sort(all(nums));
        int ans = rec(0, nums);
        return ans;
    }
};