//https://leetcode.com/problems/construct-string-with-repeat-limit/
//use 25 as idx not z as idx 
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> cnt(26,0);
        string res = "";
        for(char c : s)
            cnt[c-'a']++;
        
        for(int i = 25; i >= 0; i--) {
            int idx = 0;
            while(cnt[i] > 0 && idx < repeatLimit) {
                res += ('a' + i);
                cnt[i]--;
                idx++;
            }
            
            if(cnt[i]) {
                bool flag = false;
                for(int j = i-1; j >= 0; j--) {
                    if(cnt[j]) {
                        res += ('a'+j);
                        cnt[j]--;
                        flag = true;
                        i++;
                        break;
                    }
                }
                
                if(flag == false) break;
            }
        }
        return res;          
    }
};