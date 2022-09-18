//never use erase it gives tle here
class Solution {
public:
    string removeStars(string s) {
        int len = s.length();
        string ans = "";
        for(int i = 0; i < len; i++) {
            if(s[i] != '*') {
                ans += s[i];
            } else {
                if(ans.length()) {
                    ans.pop_back();
                }
            }
//             if(s[i] == '*') {
//                 //remove star
//                 s.erase(i, 1);
//                 i--;
//                 len--;
                
//                 //remove left characer
//                 if(i >= 0) {
//                     s.erase(i, 1);
//                     i--;
//                     len--;
//                 }
                
//                 //cout << s << endl;
//             }
        }
        
        return ans;
    }
};