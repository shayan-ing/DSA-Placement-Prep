class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));

        dp[0][0][0] = grid[0][0];

        for (int sum = 1; sum < 2 * n - 1; sum++) {
            for (int r1 = min(n - 1, sum); r1 >= 0; r1--) {
                for (int r2 = min(n - 1, sum); r2 >= 0; r2--) {
                    int c1 = sum - r1, c2 = sum - r2;

                    if (c1 < 0 || c1 >= n || c2 < 0 || c2 >= n) continue;  // Ensure valid indices  
                    if (grid[r1][c1] == -1 || grid[r2][c2] == -1) continue; // Skip thorn cells  

                    int cherries = grid[r1][c1];
                    if (r1 != r2) cherries += grid[r2][c2];

                    int best = INT_MIN;
                    if (r1 > 0 && r2 > 0) best = max(best, dp[r1-1][c1][r2-1]);  
                    if (r1 > 0 && c2 > 0) best = max(best, dp[r1-1][c1][r2]);    
                    if (c1 > 0 && r2 > 0) best = max(best, dp[r1][c1-1][r2-1]);  
                    if (c1 > 0 && c2 > 0) best = max(best, dp[r1][c1-1][r2]);    

                    if (best != INT_MIN) dp[r1][c1][r2] = cherries + best;
                }
            }
        }
        return max(0, dp[n-1][n-1][n-1]);
    }
};
