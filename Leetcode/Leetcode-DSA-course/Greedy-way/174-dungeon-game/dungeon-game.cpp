class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if (A[m - 1][n - 1] >= 0)
            dp[m - 1][n - 1] = 1;
        else
            dp[m - 1][n - 1] = 1 - A[m - 1][n - 1];

        for (int i = m - 2; i >= 0; i--) {
            if (A[i][n - 1] >= dp[i + 1][n - 1])
                dp[i][n - 1] = 1;
            else
                dp[i][n - 1] = dp[i + 1][n - 1] - A[i][n - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            if (A[m - 1][i] >= dp[m - 1][i + 1])
                dp[m - 1][i] = 1;
            else
                dp[m - 1][i] = dp[m - 1][i + 1] - A[m - 1][i];
        }

        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                int minHealth = min(dp[i + 1][j], dp[i][j + 1]);
                if (A[i][j] >= minHealth)
                    dp[i][j] = 1;
                else
                    dp[i][j] = minHealth - A[i][j];
            }
        }
        return dp[0][0];
    }
};