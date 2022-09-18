//https://leetcode.com/problems/generate-parentheses
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str =  "";
        backtrack(ans, str, n, 0, 0);
        
        return ans;
    }
    
    void backtrack(vector<string> &ans, string &cur, int mx_len, int open, int close) {
        if(cur.length() == mx_len*2) {
            ans.push_back(cur);
            return;
        }
        
        if(open < mx_len) {
            cur += "(";
            backtrack(ans, cur, mx_len, open+1, close);
            cur.pop_back();
        }
        
        if(close < open) {
            cur += ")";
            backtrack(ans, cur, mx_len, open, close+1);
            cur.pop_back();
        }
    }
};