//https://leetcode.com/problems/fair-distribution-of-cookies/

/* Using Backtracking */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kids;
    int unfairness = INT_MAX;
    
    void rec(int idx, vector<int>& cookies) {
        if(idx == cookies.size()) {
            int cur_mx = *max_element(kids.begin(), kids.end());
            unfairness = min(unfairness, cur_mx);
            return;
        }

        for(int i = 0; i < kids.size(); i++) {
            kids[i] += cookies[idx];
            rec(idx+1, cookies);
            kids[i] -= cookies[idx];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        kids.resize(k, 0);
        rec(0, cookies);
        return unfairness;
    }
};