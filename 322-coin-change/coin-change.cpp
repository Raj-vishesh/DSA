class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[n+1][amount+1];
        for(int i = 0 ; i <= n ; i++){
            for(int j = 0 ; j <= amount ; j++){
                
                if(j == 0) dp[i][j] = 0;
                else if(i ==0 ) dp[i][j] = INT_MAX -1;
            }
        }

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= amount ; j++){
                if(coins[i-1] <= j){
                    dp[i][j] = min(1+ dp[i][j-coins[i-1]] , dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        if(dp[n][amount] > amount) return -1;
        else return dp[n][amount];
    }
};