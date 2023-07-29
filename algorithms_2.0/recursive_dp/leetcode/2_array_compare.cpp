//https://leetcode.com/problems/longest-non-decreasing-subarray-from-two-arrays/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define For(i, a, n) for(ll i = a; i <= n; i++)
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 1; i--)
#define all(a) (a.begin()), (a.end())
#define memo(a) memset(a, -1, sizeof(a));
#define put(n) (cout << n << endl)
#define spaced(n) (cout << n << " ")
#define get(n) (cin >> n);
#define get2(a,b)get(a)get(b)
#define get3(a,b,c)get2(a,b)get(c)
#define get4(a,b,c,d)get2(a,b)get2(c,d)
#define get5(a,b,c,d,e)get4(a,b,c,d)get(e)
#define len(x) ((ll)x.size()) 
#define pb push_back
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
const ll MOD = 1000000007;
const long long oo = 1e16;
const ll MX = (1LL<<60);
const int LOG = 60;
const ll N = 1e5+10;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

class Solution {
public:
    int dp[100005][3];
    int rec(int idx, int arr_no, vector<int>& nums1, vector<int>& nums2) {
        if(idx == len(nums1)-1) return 1;

        if(dp[idx][arr_no] != -1) return dp[idx][arr_no];
        
        int ans1 = 1, ans2 = 1;
        if(nums1[idx+1] >= nums1[idx]) ans1 = max(ans1, 1 + rec(idx+1, 1, nums1, nums2));
        if(nums2[idx+1] >= nums1[idx]) ans1 = max(ans1, 1 + rec(idx+1, 2, nums1, nums2));

        dp[idx][1] = ans1;

        if(nums2[idx+1] >= nums2[idx]) ans2 = max(ans2, 1 + rec(idx+1, 2, nums1, nums2));
        if(nums1[idx+1] >= nums2[idx]) ans2 = max(ans2, 1 + rec(idx+1, 1, nums1, nums2));

        dp[idx][2] = ans2;

        return dp[idx][arr_no];;
    }

    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = INT_MIN;
        memo(dp);
        rep0(i, len(nums1)) {
            ans = max(ans, max(rec(i, 1, nums1, nums2), rec(i, 2, nums1, nums2)));
        }
        return ans;
    }
};