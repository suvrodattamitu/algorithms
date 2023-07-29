//https://leetcode.com/contest/weekly-contest-312/problems/sort-the-people/

class Solution {
public:    
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string, int>> a;
        
        int n = names.size();
        for(int i = 0; i < n; i++) {
            a.push_back({names[i], heights[i]});
        }
        
        sort(a.begin(), a.end(), [](const pair<string,int> &a, const pair<string,int> &b){return a.second>b.second;});
        
        vector<string> arr;
        for(auto ans : a) {
            string x = (string)ans.first;
            arr.push_back(x);
        }
                
        return arr;
    }
};