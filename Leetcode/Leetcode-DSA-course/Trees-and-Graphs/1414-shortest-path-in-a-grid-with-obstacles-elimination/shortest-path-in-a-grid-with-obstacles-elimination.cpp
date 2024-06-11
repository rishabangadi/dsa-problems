class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        queue<vector<int>> queue;
        vector<vector<int>> seen(m, vector<int>(n, -1));
        queue.push({0, 0, k, 0});
        while (!queue.empty()) {
            vector<int> curr = queue.front();
            queue.pop();
            int row = curr[0], col = curr[1], remain = curr[2], steps = curr[3];
            if (row == m - 1 && col == n - 1)
                return steps;
            if (grid[row][col] == 1) {
                if (remain == 0)
                    continue;
                remain--;
            }
            if (seen[row][col] >= remain)
                continue;
            seen[row][col] = remain;

            for (auto direction : directions) {
                int nextRow = direction[0] + row;
                int nextCol = direction[1] + col;
                if (valid(nextRow, nextCol))
                    queue.push({nextRow, nextCol, remain, steps + 1});
            }
        }
        return -1;
    }

    bool valid(int row, int col) {
        return row >= 0 && col >= 0 && row < m && col < n;
    }
};