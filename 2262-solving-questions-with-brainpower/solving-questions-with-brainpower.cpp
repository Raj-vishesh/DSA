class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long  n = questions.size();

        vector<long long > dp(n+1 , 0);

        for(int i = n-1; i >= 0 ; i--){
            long long  take = questions[i][0];
            long long  next = i+ questions[i][1] + 1;

            if(next < n){
                take += dp[next];
            }

            long long  not_take = dp[i+1];

            dp[i] = max(take , not_take);
        }


        

        return dp[0];


    }
};