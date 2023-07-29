//https://leetcode.com/problems/binary-search/?envType=study-plan&id=binary-search-i
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
    int search(vector<int>& nums, int target) {
        sort(all(nums));
        int low = 0, high = len(nums)-1, ans = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) {
                return mid; 
            }

            if(nums[mid] < target) {
                low = mid + 1;                     
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};