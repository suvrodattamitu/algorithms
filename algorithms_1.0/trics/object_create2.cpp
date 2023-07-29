//https://leetcode.com/contest/biweekly-contest-83/problems/design-a-number-container-system/
class NumberContainers {
public:
    
    map<int,set<int>> idx;
    map<int,int> num;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (num.count(index)) {
            int prev = num[index];
            idx[prev].erase(index);
            idx[number].insert(index);
            num[index] = number;
        } else {
            num[index] = number;
            idx[number].insert(index);
        }
    }
    
    int find(int number) {
        if (idx[number].size() == 0)
            return -1;
        return *idx[number].begin();
    }
};