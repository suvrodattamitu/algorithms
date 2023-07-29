//https://leetcode.com/problems/maximum-product-after-k-increments/
#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int num : nums) pq.push(num);
        
        for(int i = 0; i < k; i++) {
            int cur_num = pq.top();            
            pq.pop();
            pq.push(cur_num+1);
        }
        
        long long int ans = 1;
        while(!pq.empty()) {
            int tp = pq.top();
            pq.pop();
            ans = (ans%mod * tp%mod) % mod;
        }
        
        return ans%mod;
    }
};