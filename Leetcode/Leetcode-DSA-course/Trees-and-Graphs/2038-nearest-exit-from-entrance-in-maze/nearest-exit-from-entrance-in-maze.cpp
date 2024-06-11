class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int r, c; // entrance row, entrance column
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m = maze.size();
        n = maze[0].size();
        r = entrance[0];
        c = entrance[1];

        queue<vector<int>> queue;
        vector<vector<bool>> seen(m, vector(n, false));
        seen[r][c] = true;
        queue.push({r, c, 0});

        while (!queue.empty()) {
            auto curr = queue.front();
            queue.pop();
            int row = curr[0], col = curr[1], steps = curr[2];

            if ((row != r || col != c) &&
                (row == m - 1 || row == 0 || col == n - 1 || col == 0))
                return steps;

            for (auto& direction : directions) {
                int nextRow = row + direction[0];
                int nextCol = col + direction[1];
                if (valid(nextRow, nextCol) && maze[nextRow][nextCol] == '.' &&
                    !seen[nextRow][nextCol]) {
                    seen[nextRow][nextCol] = true;
                    queue.push({nextRow, nextCol, steps + 1});
                }
            }
        }
        return -1;
    }

    bool valid(int row, int col) {
        return row >= 0 && col >= 0 && row < m && col < n;
    }
};