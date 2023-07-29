//https://leetcode.com/problems/minimum-operations-to-halve-array-sum/
class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = 0;
        priority_queue<double> pq;
        for(int num : nums) {
            sum += num;
            pq.push(num);
        }
        
        double cur_sum = 0, need_sum = (double)(sum/2);
        int cnt = 0;
        while(cur_sum < need_sum) {
            double cur_num = pq.top()/2;
            pq.pop();
            pq.push(cur_num);
            cnt++;
            cur_sum += (cur_num);
        }
        
        return cnt;
     }
};