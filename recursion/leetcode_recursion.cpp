//https://leetcode.com/problems/find-the-punishment-number-of-an-integer/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rec(int idx, int cur_sum, int tmp_sum, string str, int target) {
        if(idx >= str.length()) {
            return (cur_sum+tmp_sum == target);
        }

        int cur = str[idx] - '0';
        if(rec(idx+1, cur_sum, tmp_sum*10+cur, str, target) || rec(idx+1, cur_sum+tmp_sum, cur, str, target)) {
            return true;
        }

        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int x = 1; x <= n; x++) {
            if(rec(0, 0, 0, to_string(x*x), x)) {
                ans += (x*x);
            }
        }

        return ans;
    }
};