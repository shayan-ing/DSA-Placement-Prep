class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        int maxprft = 0;
        int k = prices[0];
        for (int i = 1;i<n;i++){
                    int profit = prices[i]-k;
                    maxprft = max(maxprft, profit);
                    k = min(k,prices[i]);
        }
        return maxprft;
    }
};