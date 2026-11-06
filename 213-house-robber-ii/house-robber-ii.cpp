class Solution {
public:

    int solve(vector<int> &nums , int start  , int end){
        int n = nums.size();
        vector<int> dp(n, 0);

        dp[start] = nums[start];

        if(start + 1 <= end){
            dp[start +1] = max(nums[start] , nums[start+1]);
        }
        for(int i = start + 2 ; i <= end ; i++){
            int take = nums[i] + dp[i-2];
            int not_take = dp[i-1];

            dp[i] = max(take , not_take);
        }

        return dp[end];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int case2 = solve(nums, 1 , n-1);
        int case1 = solve(nums , 0 , n-2);


        return max(case1 , case2);
    }
};