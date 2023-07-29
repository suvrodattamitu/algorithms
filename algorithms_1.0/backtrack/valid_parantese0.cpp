//https://leetcode.com/problems/generate-parentheses/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;
    int open = 0, close = 0;
    void rec(string& str, int open, int close) {
        if(open == 0 && close == 0) {
            ans.push_back(str);
            return;
        }

        if(open > 0) {
            str += "(";
            rec(str, open-1, close);
            str.pop_back();
        }
        
        if(close > 0 && open < close) {
            str += ")";
            rec(str, open, close - 1);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string str = "";
        rec(str, n, n);
        return ans;
    }
};