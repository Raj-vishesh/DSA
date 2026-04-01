class Solution {
public:

    int countSubsetSum(vector<int>& nums , int diff){
        int n = nums.size();

        int dp[n+1][diff+1];

        for(int i = 0 ; i <= n ; i++){
            for(int j = 0 ; j <= diff ; j++){
                if(i == 0) dp[i][j] = 0;
                if(j == 0) dp[i][j] = 1;

            }
        }

        for(int i = 1 ; i <= n ; i++){
            for(int j = 0 ; j <= diff ; j++){
                if(nums[i-1] <= j ){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][diff];
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int totalSum = accumulate(nums.begin() , nums.end() , 0);

        if(abs(target) > totalSum  || (totalSum + target) %2 != 0) return 0;

        int s1 = (totalSum + target) /2;

        return countSubsetSum(nums , s1);
        
    }
};