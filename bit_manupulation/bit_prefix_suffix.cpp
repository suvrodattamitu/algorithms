//https://leetcode.com/contest/biweekly-contest-104/problems/maximum-or/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumOr(vector<int>& a, int k) {
        int n = a.size();
        vector<int> p(n + 1);
        for (int i = 0; i < n; i++) {
            p[i + 1] = p[i] | a[i];
        }
        vector<int> s(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            s[i] = s[i + 1] | a[i];
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long x = a[i];
            //(x << k) multiply x with 2 k times, ex (5<<1) = 5*2; (3<<3) = 3*2*2*2
            ans = max(ans, (x << k) | p[i] | s[i + 1]); 
        }
        return ans;
    }
};