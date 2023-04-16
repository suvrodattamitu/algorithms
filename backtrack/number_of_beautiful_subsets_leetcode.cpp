//https://leetcode.com/problems/the-number-of-beautiful-subsets/description/
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
    int ans = 0;
    unordered_map<int, int> mp;

    // rec Helper for recursing through list building a unique subset
    void rec(vector<int> &nums, int idx, int k) {
        // If we have reached the end of the list, count this unique subset
        if(idx == nums.size()) ans++;
        else {
            // Otherwise, we need to recurse, if possible recurse taking this element for the subset
            if(!mp[nums[idx] - k] && !mp[nums[idx] + k]) {
                mp[nums[idx]]++;
                rec(nums, idx + 1, k);
                mp[nums[idx]]--;
            }
            // Recurse without taking this element in the subset
            rec(nums, idx + 1, k);
        }
    }
    
    // O(2^N) Solution that generates all valid subsets and counts them in the result variable
    int beautifulSubsets(vector<int>& nums, int k) {
        // rec through the numbers array from index 0
        rec(nums, 0, k);
        // Return all of the counted sets - 1 for the empty set
        return ans - 1;
    }
};