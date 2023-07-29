//https://leetcode.com/contest/weekly-contest-261/problems/stone-game-ix/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> c(3);
        for (int x : stones) c[x % 3] += 1;

        if (!c[1] && !c[2]) return false;

        if (c[0] % 2 == 0) {
            if (c[1] and c[1] - 1 < c[2]) return true;
            if (c[2] and c[2] - 1 < c[1]) return true;
        } else {
            if (c[1] and c[2] < c[1] - 2) return true;
            if (c[2] and c[1] < c[2] - 2) return true;
        }
        return false;
    }
};