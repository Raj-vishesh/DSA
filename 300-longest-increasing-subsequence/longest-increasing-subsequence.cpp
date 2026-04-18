class Solution {
public:
    //   BUt this code will  give us the TLE 
    // int solve(int idx , int prev_idx , vector<int> &nums , vector<vector<int>> &dp){
    //     int n = nums.size();
    //     if(idx == n) return 0;

    //     if(dp[idx][prev_idx+1] != -1) {
    //         return dp[idx][prev_idx+1];
    //     }
    //     int notake = solve(idx+1 , prev_idx , nums , dp);
    //     int take = 0;
    //     if(prev_idx == -1 || nums[idx] > nums[prev_idx]){
    //         take = 1+ solve(idx+1 , idx , nums , dp);
    //     }

    //     return dp[idx][prev_idx+1] =  max(take , notake);
    // }
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>> dp(n , vector<int> (n+1 , -1));
        // return solve(0 , -1 , nums , dp);

        int n = nums.size();
        vector<int> dp(n , 1);

        int maxlen = 1;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[i]  > nums[j]){
                    dp[i] = max(dp[i] , dp[j] + 1);
                }
            }

            maxlen = max(maxlen , dp[i]);
        }

        return maxlen;
    }
};