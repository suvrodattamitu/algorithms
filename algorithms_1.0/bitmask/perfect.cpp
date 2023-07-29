//https://leetcode.com/problems/find-the-punishment-number-of-an-integer/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll int, ll int>
#define ff first
#define ss second
#define pb push_back
#pragma GCC optimize("O2")
using namespace std;
class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int x = 1; x <= n; x++) {
            int cur = x * x;
            vector<int> v;
            while (cur) {
                v.pb(cur % 10);
                cur /= 10;
            }
            reverse(v.begin(), v.end());
            bool valid = false;
            for (int conf = 0; conf < (1 << 7); conf++) {
                int roll = v[0];
                int sum = 0;
                for (int i = 1; i < (int)(v.size()); i++) {
                    if (conf & (1 << (i - 1))) {
                        sum += roll;
                        roll = v[i];
                    } else {
                        roll = roll * 10 + v[i];
                    }
                }
                sum += roll;
                if (sum == x) {
                    valid = true;
                    break;
                }
            }
            if (valid) {
                ans += x * x;
            }
        }
        return ans;
    }
};