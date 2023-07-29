//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
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
    bool check(vector<int>& weights, int days, int capacity) {
        int currWeight = 0, NoOfDaysRequired = 1;
        for(int weight : weights) {
            if(currWeight + weight <= capacity) {
                currWeight += weight;
            }
            else if(weight <= capacity) {
                NoOfDaysRequired++;
                currWeight = weight;
            }
            else {
                return false;
            }
        }
 
        return NoOfDaysRequired <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int lo = 0, hi = accumulate(weights.begin(), weights.end(), 0);

        int ans = 0;
        while(lo <= hi) {
            int mid = (lo+hi) / 2;
            if(check(weights, days, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1; 
            }
        }

        return ans;
    }
};