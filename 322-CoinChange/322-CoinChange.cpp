class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
         vector<int> dp(amount + 1, INT_MAX);  // Step 1: Create DP array
        dp[0] = 0;  // Base case: 0 coins needed for amount = 0

        for (int i = 1; i <= amount; i++) {  // Iterate over each amount
            for (int index = 0; index < coins.size(); index++) {  // Iterate over each coin
                int coin = coins[index];  // Get the coin value

                if (i >= coin && dp[i - coin] != INT_MAX) {  // Valid case check
                    dp[i] = min(dp[i], dp[i - coin] + 1);  // Update DP value
                }
            }
        }

        // Beginner-friendly return statement
        if (dp[amount] == INT_MAX) {
            return -1;  // If amount is unreachable, return -1
        } else {
            return dp[amount];  // Otherwise, return the minimum number of coins
        }
    }
};