//https://leetcode.com/problems/most-profit-assigning-work
class Solution {
public:
    int binarySearch(vector<pair<int, int>> &data, int ability) {
        int low = 0, high = data.size()-1, ans = 0;
        while(low <= high) {
            int mid = (low + high)/2;
            if(data[mid].first <= ability) {
                low = mid + 1;
                ans = data[mid].second;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
    
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& abilities) { 
        int n = difficulty.size();
        
        vector<pair<int, int>> data;
        for(int i = 0; i < n; i++) {
            data.push_back({difficulty[i], profit[i]});
        }
        
        sort(data.begin(), data.end());
        
        for(int i = 1; i < n; i++) {
            int x = max(data[i].second, data[i-1].second);
            data[i].second = x;
        }
             
        int total = 0;
        for(int ability : abilities) {
            int val = binarySearch(data, ability);
            total += val;
        }
        
        return total;
    }
};