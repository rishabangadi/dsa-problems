class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            int count = INT_MAX;
            for (int coin : coins) {
                if (coin <= i && dp[i - coin] != -1)
                    count = min(count, dp[i - coin] + 1);
            }
            if (count != INT_MAX)
                dp[i] = count;
        }
        return dp[amount];
    }
};