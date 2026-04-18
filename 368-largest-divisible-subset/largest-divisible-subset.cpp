class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n , -1);

        sort(nums.begin() , nums.end());

        int max_len = 1;
        int last_idx = 0;

        for(int i = 0 ; i < n ; i++){
            // hash[i] = i;
            for(int j = 0 ; j < i; j++){
                if(nums[i] % nums[j] == 0 &&  1+ dp[j] > dp[i]){
                    dp[i] = 1+ dp[j];
                    hash[i] = j;
                }
            }

            if(max_len < dp[i]){
                max_len = dp[i];
                last_idx = i;
            }

        }
        vector<int> temp;

        while(last_idx != -1){
            temp.push_back(nums[last_idx]);
            last_idx = hash[last_idx];
        }

        return temp;


    }
};