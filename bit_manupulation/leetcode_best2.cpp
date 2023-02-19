//https://leetcode.com/contest/biweekly-contest-89/problems/range-product-queries-of-powers/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) { 
        vector<int> a;
        for(int i = 0; i < 31; i++) {
            if(n & (1<<i)) { // you can use if(n >> i & 1) too
                a.push_back(1<<i);
            }
        }
        
        vector<int> b;
        ll mod = 1e9+7;
        for(auto u : queries) {
            int l = u[0], r = u[1];
            
            ll ans = 1;
            for(int i = l; i <= r; i++)
                ans = ans * a[i] % mod;
            b.push_back(ans);
        }
        return b;
    }
};