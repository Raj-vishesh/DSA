class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int profit = 0;

        for(int i = 1 ; i < n ; i++){
            mini = min(mini , prices[i]);

            int current_profit = prices[i] - mini;

            profit = max(profit , current_profit);

        }

        return profit;
    }
};