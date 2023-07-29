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

class Solution {
public:
    ll dp[15][2<<15];
    ll rec(int idx, int mask, int flag, vector<int>& nums) {
        if (idx == len(nums)) return 1;
        
        if (dp[flag + 1][mask] != -1) {
            return dp[flag + 1][mask];
        }
        
        ll tot = 0;
        for (int j = 0; j < len(nums); ++j) {
            if ((mask & (1 << j)) != 0) {
                continue;
            }
            
            if (flag == -1 || (nums[flag] % nums[j] == 0) || (nums[j] % nums[flag] == 0)) {
                tot += rec(idx+1, mask | (1 << j), j, nums);
                tot %= MOD;
            }
        }
            
        return dp[flag + 1][mask] = tot;
    }
    
    int specialPerm(vector<int>& nums) {
        memo(dp);
        int ans = rec(0, 0, -1, nums);      
        return ans;
    }
};