class Solution {
public:
    int robHelper(vector<int>& nums) {
        int n = nums.size();
        if( n == 0) return 0;
        if(n == 1) return nums[0];
        
        vector<int> dp(n , 0);
        dp[0] = nums[0];

        for(int i = 1; i < n ; i++){
            int take = nums[i] ;
            if(i > 1 ){
                take += dp[i-2];
            }
            int notTake = (0 + dp[i-1]);

            dp[i] = max(take , notTake);
        }

        return dp[n-1];

    }

    int rob(vector<int>& nums){
        int n = nums.size();
        if( n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> temp1;
        for(int i = 0 ; i < n -1 ; i++){
            temp1.push_back(nums[i]);
        }

        vector<int> temp2;
        for(int i =1  ; i < n ; i++){
            temp2.push_back(nums[i]);
        }

        int ans1 = robHelper(temp1);
        int ans2 = robHelper(temp2);

        return max(ans1 , ans2 );
    }
};