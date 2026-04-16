class Solution {
public:
    int dp[30001][2];

    int f(int idx, int buy, vector<int>& prices) {
        int n = prices.size();

        if (idx == n) return 0;

        if (dp[idx][buy] != -1) {
            return dp[idx][buy];
        }

        int profit = 0;

        if (buy) {
            profit = max(
                -prices[idx] + f(idx + 1, 0, prices),
                f(idx + 1, 1, prices)
            );
        } 
        else {
            profit = max(
                prices[idx] + f(idx + 1, 1, prices),
                f(idx + 1, 0, prices)
            );
        }

        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return f(0, 1, prices);
    }
};