//https://leetcode.com/problems/maximum-swap
class Solution {
public:
    int maximumSwap(int num) {
        ostringstream oss; oss << num;
        string str = oss.str();
        
        // search for the largest digit in range
        for (int i = 0; i < str.size(); i++) {
            auto m = max_element(str.rbegin(), str.rbegin() + str.size() - i);
            if (*m == str[i]) continue;
            int idx = str.size() - 1 - distance(str.rbegin(), m);
            swap(str[i], str[idx]);
            return atoi(str.c_str());
        }
        
        return atoi(str.c_str());
    }
};