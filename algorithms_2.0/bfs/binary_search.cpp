//https://leetcode.com/problems/last-day-where-you-can-still-cross/description/
class Solution {
public:
    vector<pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // Possible directions
    bool is_possible(int rows, int cols, int mid, vector<vector<int>>& cells) {
        vector<vector<int>> grid(rows + 1, vector<int>(cols + 1, 0)); // Grid representation
        for (int i = 0; i < mid; i++) {
            grid[cells[i][0]][cells[i][1]] = 1; // Mark cells from the given list as blocked
        }

        queue<pair<int, int>> q;
        
        for (int i = 1; i <= cols; i++) {
            if (grid[1][i] == 0) {
                q.push({1, i}); // Start BFS from the top row
                grid[1][i] = 1; // Mark the cell as visited
            }
        }

        while (!q.empty()) {
            auto tp = q.front();
            q.pop();

            int r = tp.first, c = tp.second; // Current cell coordinates
            for (auto d : directions) {
                int rr = r + d.first, cc = c + d.second; // Neighbor cell coordinates
                if (rr > 0 && cc > 0 && rr <= rows && cc <= cols && grid[rr][cc] == 0) {
                    grid[rr][cc] = 1; // Mark the neighbor cell as visited
                    if (rr == rows) {
                        return true; // Found a path to the bottom row
                    }
                    q.push({rr, cc}); // Add the neighbor cell to the queue for further exploration
                }
            }
        }
        
        return false; // Unable to find a path to the bottom row
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 0, high = row * col, latestPossibleDay = 0;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(is_possible(row, col, mid, cells)) {
               low = mid + 1;
               latestPossibleDay = mid;
            } else {
               high = mid - 1;
            }
        } 

        return latestPossibleDay;
    }
};