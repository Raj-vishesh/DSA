class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int> (n , 1));

        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                int from_above = dp[i-1][j];
                int from_left = dp[i][j-1];
                dp[i][j] = from_above + from_left;
            }
        }

        return dp[m-1][n-1];
    }
};