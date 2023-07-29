//https://leetcode.com/problems/collecting-chocolates/description/

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


// solution 1
class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = len(nums);
        ll ans = LONG_MAX;

        vector<int> arr(n, INT_MAX);
        rep0(r, n) {
            ll res = r * x;
            rep0(i, n) {
                arr[i] = min(arr[i], nums[(i+r)%n]);
                res += arr[i];
            }

            ans = min(ans, res);
        }

        return ans;
    }
};

// solution 2
class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        long long ans = LONG_MAX;
        int n = len(nums);

        vector<int> arr(n, INT_MAX);
        vector<int> cnums(nums.begin(), nums.end());
        for(auto num : nums) cnums.push_back(num);

        rep0(r, n) {
            ll sum = r * x;
            rep0(i, n) {
                arr[i] = min(arr[i], cnums[r+i]);
                sum += arr[i];
            }

            ans = min(ans, sum);
        }

        return ans;
    }
};