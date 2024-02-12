class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> dic;
        for (auto row : grid)
            dic[row]++;
        map<vector<int>, int> dic2;
        for (int col = 0; col < grid[0].size(); col++) {
            vector<int> currentCol;
            for (int row = 0; row < grid.size(); row++)
                currentCol.push_back(grid[row][col]);
            dic2[currentCol]++;
        }
        int ans = 0;
        for (auto [arr, val] : dic) {
            ans += val * dic2[arr];
        }
        return ans;
    }
};