//https://leetcode.com/contest/weekly-contest-332/problems/count-the-number-of-fair-pairs/
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
    long long countFairPairs(vector<int>& a, int lower, int upper) {
        sort(a.begin(), a.end());
        long long ret = 0;
        rep0(i, len(a)) {
            ret += upper_bound(a.begin() + (i+1), a.end(), upper-a[i]) - lower_bound(a.begin()+ (i+1), a.end(), lower-a[i]);
        }
        return ret;
    }
};