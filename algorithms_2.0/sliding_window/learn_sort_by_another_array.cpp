//https://leetcode.com/problems/count-zero-request-servers/description/
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& qs) {
        sort(begin(logs), end(logs), [](const auto &l1, const auto &l2){ return l1[1] < l2[1]; });

        vector<int> ids(qs.size()), res(qs.size()), cnt(n + 1);

        iota(begin(ids), end(ids), 0);
        sort(begin(ids), end(ids), [&](int i, int j){ return qs[i] < qs[j]; });

        int i = 0, j = 0, used = 0;
        for (int id : ids) {
            for (; i < logs.size() && logs[i][1] <= qs[id]; ++i)
                used += (++cnt[logs[i][0]] == 1);
            for (; j < logs.size() && logs[j][1] < qs[id] - x; ++j)
                used -= (--cnt[logs[j][0]] == 0);
            res[id] = n - used;
        }

        return res;
    }
};