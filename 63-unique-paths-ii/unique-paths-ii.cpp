class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        //  base case jese 1sta nd last me hi obstacle aa gya ho 
        if(obstacleGrid[0][0] ==1 || obstacleGrid[n-1][m-1] == 1){
            return 0;

        }


        vector<vector<int>> dp(n , vector<int> (m, 0));
        dp[0][0] =1 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                // agar vo grid obstacle hai to return 0 
                if(obstacleGrid[i][j] ==1 )   dp[i][j] = 0;
                         
                // agar udhar obstacle nahi aa rha to left and up ka ans store kro 
                else{
                    

                    if(i > 0) dp[i][j] += dp[i-1][j];
                    if(j > 0) dp[i][j] += dp[i][j-1];
                    
                }
            }
        }

        return dp[n-1][m-1];
    }
};