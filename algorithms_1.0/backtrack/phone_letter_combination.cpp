//https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;
    vector<string> pad;

    string temp = "";
    void backtrack(string &digits, int idx) {
        if(idx >= digits.length()) {
            ans.push_back(temp); 
            return;
        }

        string chrs = pad[digits[idx]-'0'];
        for(char c : chrs) {
            temp.push_back(c);
            backtrack(digits, idx+1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return ans;
        pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtrack(digits, 0);
        return ans;
    }
};