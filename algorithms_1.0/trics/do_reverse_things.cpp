//https://leetcode.com/contest/weekly-contest-344/problems/find-the-distinct-difference-array/
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
    vector<int> distinctDifferenceArray(vector<int>& A) {
        int n = A.size();
        vector<int> ret(n);
        unordered_set<int> hs;
        rep0(i, n) {
            hs.insert(A[i]);
            ret[i] += hs.size();
        }
        hs.clear();
        rrep0(i, n) {
            ret[i] -= hs.size();
            hs.insert(A[i]);
        }
        return ret;
    }
};

//https://leetcode.com/contest/weekly-contest-344/problems/number-of-adjacent-elements-with-the-same-color/
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> ans(queries.size()), colors(n+1, 0);
        
        int curr = 0;
        for(int i = 0; i < queries.size(); i++) {
            int idx = queries[i][0], color = queries[i][1], found = 0;  
            
            int prv_color = colors[idx];
            if(prv_color && idx-1 >= 0 && colors[idx-1] == prv_color) {
                --curr;
            } 

            if(prv_color && idx-1 < n && colors[idx+1] == prv_color) {
                --curr;
            }
                        
            colors[idx] = color;
            if(color && idx-1 >= 0 && colors[idx-1] == color) {
                ++curr;
            }
            
            if(color && idx+1 < n && colors[idx+1] == color) {
               ++curr; 
            }
            
            ans[i] = curr;
        }
        
        return ans;
    }
};