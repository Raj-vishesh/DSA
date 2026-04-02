class Solution {
public:
    int m, n;
    vector<vector<int>> coins;
    int dp[505][505][3];

    int solve(int i, int j, int k) {
        if (i >= m || j >= n) return -1e9;

        if (dp[i][j][k] != -1e9) return dp[i][j][k];

        if (i == m - 1 && j == n - 1) {
            if (coins[i][j] < 0 && k > 0) return 0;
            return coins[i][j];
        }

        int ans = coins[i][j] + max(solve(i + 1, j, k), solve(i, j + 1, k));

        if (coins[i][j] < 0 && k > 0) {
            ans = max(ans, max(solve(i + 1, j, k - 1), solve(i, j + 1, k - 1)));
        }

        return dp[i][j][k] = ans;
    }

    int maximumAmount(vector<vector<int>>& grid) {
        coins = grid;
        m = coins.size();
        n = coins[0].size();

        for (int i = 0; i < 505; i++) {
            for (int j = 0; j < 505; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = -1e9;
                }
            }
        }

        return solve(0, 0, 2);
    }
};