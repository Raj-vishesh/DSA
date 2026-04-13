class Solution {
public:

    
    int rob(vector<int>& nums) {
        int n = nums.size();
        // Edge Case 
        if(n == 0 ) return 0;
        if(n == 1) return nums[0];
        vector<int> dp(n , 0);
        // Base Case 
        dp[0] = nums[0];
        

        

        for(int i = 1; i < n ; i++){
            int take  = nums[i] ;

            if(i > 1){
                take += dp[i-2];
            }
            int notTake = 0 + dp[i-1];
            dp[i] = max(take ,  notTake);
        }
        return dp[n-1];
    }
};