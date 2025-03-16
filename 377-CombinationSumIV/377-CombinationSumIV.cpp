class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);  // DP array to store ways to reach sum
        dp[0] = 1;  // Base case: One way to make sum 0 (using no elements)

        for (int i = 1; i <= target; i++) {  // Iterate over all target values
            for (int index = 0; index < nums.size(); index++) {  // Iterate over each number
                int num = nums[index];  // Extract the number

                if (i >= num) {  // If the number can be used
                    dp[i] += dp[i - num];  // Add ways to make (i - num)
                }
            }
        }

        return dp[target];  // Return total ways to reach target
    }
};