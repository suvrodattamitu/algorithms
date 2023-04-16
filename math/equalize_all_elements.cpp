//https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        //we can sort the array and get median or do this
        nth_element(nums.begin(), nums.begin() + (n/2), nums.end());

        int ans = 0, median = nums[n/2];
        for(int num : nums) {
            ans += abs(num - median);
        }

        return ans;
    }
};

//https://leetcode.com/problems/make-k-subarray-sums-equal/description/ 

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
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        ll sz = len(arr), res = 0;

        for (int i = 0; i < k; ++i) {
            vector<int> cycle;
            for (int j = i; arr[j] != -1; j = (j + k) % sz) {
                cycle.push_back(arr[j]);
                arr[j] = -1;
            }

            nth_element(begin(cycle), begin(cycle) + cycle.size() / 2, end(cycle));

            for (int num : cycle) {
                res += abs(num - cycle[len(cycle) / 2]);
            }
        }
        return res;
    }
};