//https://leetcode.com/contest/weekly-contest-313/problems/minimize-xor/

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = __builtin_popcount(num2), ans = 0;
        
        //take all set bit which exists in num1
        for(int i = 30; i >= 0; --i) {
            if(cnt > 0 && (num1 & 1<<i)) {
                ans += 1<<i;
                --cnt;
            }
        }
        
        //break ans and show which bit is 0 and which bit is 1

        //here we will take first 0's in ans bits
        for(int i = 0; i <= 30; ++i) {
            if(cnt > 0 && !(ans >> i&1)) {
                ans += 1<<i;
                --cnt;
            }
        }
        
        return ans;
    }
};