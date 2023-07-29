//https://leetcode.com/problems/partition-string-into-minimum-beautiful-substrings/description/

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
    int dp[18];
    bool isPowerOf5(vi& arr) {
        string str(all(arr));
        
        // convert the binary representation of number into a number
        bitset<32> bitsetNumber(str);
        ll num = (ll) bitsetNumber.to_ulong();
        
        if (num == 0) return false;
        while (num > 1) {
            if (num % 5 != 0) return false;
            num /= 5;
        }

        return true;
    }

    int rec(int idx, string& s) {
        if(idx == len(s)) return 0;
        if(s[idx] == '0') return 1e9;
        
        if(dp[idx] != -1) return dp[idx];

        int ans = 1e9;
        vi arr;
        for(int i = idx; i < len(s); i++) { 
            arr.pb(s[i]);
            if(isPowerOf5(arr)) {
                ans = min(ans, 1 + rec(i+1, s));
            }
        }

        return dp[idx] = ans;
    }
    
    int minimumBeautifulSubstrings(string s) {
        memo(dp);
        int ans = rec(0, s);
        if(ans == 1e9) ans = -1;
        return ans;
    }
};