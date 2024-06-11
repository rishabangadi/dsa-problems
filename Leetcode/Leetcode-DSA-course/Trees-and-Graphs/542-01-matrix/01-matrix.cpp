class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        queue<vector<int>> queue;

        for (int row = 0; row < m; row++)
            for (int col = 0; col < n; col++)
                if (mat[row][col] == 0) {
                    seen[row][col] = true;
                    queue.push({row, col, 1});
                }

        while (!queue.empty()) {
            vector<int> curr = queue.front();
            queue.pop();
            int row = curr[0], col = curr[1], steps = curr[2];
            for (vector<int>& direction : directions) {
                int nextRow = row + direction[0];
                int nextCol = col + direction[1];
                if (valid(nextRow, nextCol) &&
                    seen[nextRow][nextCol] == false) {
                    seen[nextRow][nextCol] = true;
                    queue.push({nextRow, nextCol, steps + 1});
                    mat[nextRow][nextCol] = steps;
                }
            }
        }
        return mat;
    }

    bool valid(int row, int col) {
        return row >= 0 && col >= 0 && row < m && col < n;
    }
};