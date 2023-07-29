//https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep0(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define rrep0(i, n) for(int i = n-1; i >= 0; i--)
#define rrep1(i, n) for(int i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define put(n) (cout << n << endl)
#define get(n) (cin >> n)
#define lens(str) ((int)str.length())
#define lena(arr) ((int)arr.size()) 
#define pb push_back
const int MOD = 1000000007;
const int N = 1e5+10;
typedef vector<ll> vi;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<ll, ll> f;
        long ans = 0;
        int dup = 0;
        long s = 0;
        int n = lena(nums);
        for(int i = 0;i < k-1;i++){
            s += nums[i];
            if(++f[nums[i]] == 2){
                dup++;
            }
        }
        for(int i = k-1;i < n;i++) {
            s += nums[i];
            if(++f[nums[i]] == 2) dup++;
            if(dup == 0) {
                ans = max(ans, s);
            }
            s -= nums[i-(k-1)];
            if(--f[nums[i-(k-1)]] == 1) dup--;
        }
        return ans;
    }
};