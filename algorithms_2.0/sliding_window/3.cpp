//https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/
class Solution {
public:
    int maxConsecutiveAnswers(string str, int k) {
        int n = str.length(), left = 0, cnt = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            if(str[i] == 'T') {
                ++cnt;
            }

            while(cnt > k) {
                if(str[left] == 'T') {
                    --cnt;
                }

                left++;
            }

            ans = max(ans, i - left + 1);
        }

        left = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            if(str[i] == 'F') {
                ++cnt;
            }

            while(cnt > k) {
                if(str[left] == 'F') {
                    --cnt;
                }

                left++;
            }

            ans = max(ans, i - left + 1);
        }

        return ans;
    }
};