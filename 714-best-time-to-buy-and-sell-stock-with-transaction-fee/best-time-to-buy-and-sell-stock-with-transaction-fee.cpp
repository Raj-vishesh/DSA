class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
       // *****    this code is not space optimized as s.c = O(n);********



        // vector<vector<int>> dp(n+1 , vector<int> (2 , 0));

        // for(int idx = n-1 ; idx >= 0 ; idx--){
        //     for(int buy = 0 ; buy <= 1 ; buy++){
        //         if(buy){
        //             dp[idx][buy] = max(-prices[idx] + dp[idx+1][0] , dp[idx+1][1]);
        //         }
        //         else{
        //             dp[idx][buy] = max(prices[idx] - fee + dp[idx+1][1] , dp[idx+1][0]); 
        //         }
        //     }
        // }

        // return dp[0][1];



        //    Space optimized bu using ahead and curr vector of 2 size ;;;;;**********************

        vector<int> ahead(2,0) , curr(2 , 0);

        for(int idx = n-1 ; idx>= 0 ; idx--){
            // buy
            curr[1] = max(-prices[idx] + ahead[0] , ahead[1]);
            
            // sell
            curr[0] = max(prices[idx] - fee + ahead[1] , ahead[0]);

            ahead = curr;
        }


        return ahead[1];

    }
};