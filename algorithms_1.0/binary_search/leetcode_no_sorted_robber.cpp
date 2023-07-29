//https://leetcode.com/problems/house-robber-iv/description/
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
    int find(int mid, vector<int>& a) {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] <= mid) {
                cnt++;
                i++;
            }
        }
        return cnt;
    }

    int minCapability(vector<int>& a, int k) {
        int l = 1, r = 1e9, ans = r;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (find(mid, a) >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};