class Solution {
public:
    vector<vector<int>> grid;
    int n;
    vector<vector<int>> directions = {{0, 1}, {1, 0},  {-1, 0},  {0, -1},
                                      {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1)
            return -1;
        n = grid.size();
        this->grid = grid;
        vector<vector<bool>> seen(n, vector<bool>(n, false));
        seen[0][0] = true;
        queue<vector<int>> queue;
        queue.push({0, 0, 1});
        while (!queue.empty()) {
            vector<int> curr = queue.front();
            queue.pop();
            int row = curr[0], col = curr[1], level = curr[2];
            if (row == n - 1 && col == n - 1)
                return level;
            for (vector<int>& direction : directions) {
                int nextRow = row + direction[0], nextCol = col + direction[1];
                if (isValid(nextRow, nextCol) && !seen[nextRow][nextCol]) {
                    seen[nextRow][nextCol] = true;
                    queue.push({nextRow, nextCol, level + 1});
                }
            }
        }
        return -1;
    }

    bool isValid(int row, int col) {
        return row >= 0 && row < n && col >= 0 && col < n &&
               grid[row][col] == 0;
    }
};