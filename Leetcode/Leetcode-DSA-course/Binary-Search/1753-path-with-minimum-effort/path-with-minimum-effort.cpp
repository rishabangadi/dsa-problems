class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        int left = 0, right = 0;
        for (auto& row : heights)
            for (int num : row)
                right = max(right, num);

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid, heights))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }

    bool check(int mid, vector<vector<int>>& heights) {
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        seen[0][0] = true;
        stack<pair<int, int>> stack;
        stack.push({0, 0});
        while (!stack.empty()) {
            auto [row, col] = stack.top();
            stack.pop();
            if (row == m - 1 && col == n - 1)
                return true;
            for (auto& direction : directions) {
                int nextRow = row + direction[0], nextCol = col + direction[1];
                if (valid(nextRow, nextCol) && !seen[nextRow][nextCol]) {
                    if (abs(heights[nextRow][nextCol] - heights[row][col]) <=
                        mid) {
                        seen[nextRow][nextCol] = true;
                        stack.push({nextRow, nextCol});
                    }
                }
            }
        }
        return false;
    }

    bool valid(int row, int col) {
        return (row >= 0 && col >= 0 && row <= m - 1 && col <= n - 1);
    }
};