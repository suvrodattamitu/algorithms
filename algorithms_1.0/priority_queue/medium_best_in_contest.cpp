//https://leetcode.com/contest/biweekly-contest-96/problems/maximum-subsequence-score/
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
#define len(arr) ((ll)arr.size()) 
#define pb push_back
const ll MOD = 1000000007;
const ll N = 1e5+10;
typedef vector<int> vi;
typedef pair<ll, ll> pii;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = len(nums1);
        vector<pair<int, int>> arr(n);
        rep0(i, n) {
            arr[i].first    = nums2[i];
            arr[i].second   = nums1[i];
        }
        
        sort(all(arr), [](const pair<int,int> &a, const pair<int,int> &b){ return a.first > b.first; });
        
        ll ans = 0, sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        rep0(i, n) {
            pq.push(arr[i].second);
            sum += arr[i].second;
            
            while(pq.size() > k) {
                int tp = pq.top();
                sum -= tp;
                pq.pop();
            }
            
            if(pq.size() == k) {
                ans = max(ans, sum * arr[i].first);
            }
        }
        
        return ans;
    }
};