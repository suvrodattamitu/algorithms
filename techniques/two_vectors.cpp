//https://leetcode.com/submissions/detail/743302768/
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        
        vector<char> a, b;
        vector<int> x, y;
        for(int i = 0; i < n; i++) {
            if(start[i] != '_') {
                a.push_back(start[i]);
                x.push_back(i);
            }
            
            if(target[i] != '_') {
                b.push_back(target[i]);
                y.push_back(i);
            }
        }
        
        if(a != b) return 0;
        
        for(int i = 0; i < x.size(); i++) {
            if(a[i] == 'L') {
                if(x[i] < y[i]) return 0;
            }
            
            if(a[i] == 'R') {
                if(x[i] > y[i]) return 0;
            }
        }
        
        return 1;
    }
};