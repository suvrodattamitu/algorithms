//https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/description/
#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define ull unsigned long long
#define For(i, a, n) for(ll i = a; i <= n; i++)
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 0; i--)
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
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = len(requests), ans = 0;
        for(int mask = 0; mask < (1 << m); mask++) {
            int cnt = 0;
            vector<int> degree(n, 0);
            for(int i = 0; i < m; i++) { // try all combination
                if(mask & (1 << i)) {
                    int x = requests[i][0], y = requests[i][1];
                    degree[x]--;
                    degree[y]++;
                    ++cnt;
                }
            }

            bool flag = true;
            for(int i = 0; i < n; i++)  { // we have to check who produce 0 in all degree, to be valid requests..
                if(degree[i] != 0)  {
                    flag = false;
                    break;
                }
            }

            if(flag) ans = max(ans, cnt); // if all degree is 0 then we have to take maximum numbers of requests
        }

        return ans;
    }
};