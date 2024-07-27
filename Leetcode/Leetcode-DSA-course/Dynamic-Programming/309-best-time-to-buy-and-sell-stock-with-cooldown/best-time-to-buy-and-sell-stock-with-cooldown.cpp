class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int holding = 0; holding < 2; holding++) {
                int ans = dp[i + 1][holding];
                if (holding == 0)
                    ans = max(ans, -prices[i] + dp[i + 1][1]);
                else
                    ans = max(ans, prices[i] + dp[i + 2][0]);
                dp[i][holding] = ans;
            }
        }
        return dp[0][0];
    }
};

