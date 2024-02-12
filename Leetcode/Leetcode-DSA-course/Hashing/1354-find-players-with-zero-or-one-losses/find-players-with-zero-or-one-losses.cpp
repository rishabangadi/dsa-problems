class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> counts(100001, -1);

        for (auto match : matches) {
            int winner = match[0], loser = match[1];
            if (counts[winner] == -1)
                counts[winner] = 0;
            if (counts[loser] == -1)
                counts[loser] = 1;
            else
                counts[loser]++;
        }

        vector<vector<int>> ans(2, vector<int>());
        for (int i = 0; i < 100001; i++) {
            if (counts[i] == 0)
                ans[0].push_back(i);
            else if (counts[i] == 1)
                ans[1].push_back(i);
        }
        return ans;
    }
};