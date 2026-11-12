class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n+1 , 0);

        
        dp[1] = nums[0];
        

        for(int i =2 ; i <= n ; i++){
            dp[i] = max(nums[i-1]  , nums[i-1] + dp[i-1]);
        }

        int ans = dp[1];

        for(int i =2 ; i<=n ; i++){
            ans = max(ans , dp[i]);
        }
        return ans;
    }
};