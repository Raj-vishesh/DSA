class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1 , 0);

        dp[0] =1 ;
        dp[1] =1; 

        for(int node = 2 ; node <= n ; node++){
            for(int root = 1 ; root <= node ; root++){
                dp[node] += dp[root -1 ] * dp[node  - root];
            }
        }

        return dp[n];
    }
};