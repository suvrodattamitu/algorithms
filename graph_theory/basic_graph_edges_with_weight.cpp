//https://leetcode.com/contest/biweekly-contest-93/problems/maximum-star-sum-of-a-graph/
#include<bits/stdc++.h>
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
#define lens(str) ((ll)str.length())
#define lena(arr) ((ll)arr.size()) 
#define pb push_back
const ll MOD = 1000000007;
const long long oo = 1e16;
const ll N = 1e5+10;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        
        vector<vector<int>> v(n);
        for(auto x : edges)
        {
            v[x[0]].push_back(vals[x[1]]);
            v[x[1]].push_back(vals[x[0]]);
        }
        
        vector<int> ans(n,0);
        rep0(i, n) {
            ans[i] = vals[i];
            sort(all(v[i]), greater<int>());
        
            for(int j = 0; j < min((int)v[i].size(), k); j++)
                ans[i] += max(0, v[i][j]);
        }
        
        int mx = *max_element(all(ans));
        return mx;
    }
};