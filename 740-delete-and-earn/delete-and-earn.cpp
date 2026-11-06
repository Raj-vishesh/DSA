class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());

        vector<int> dp(maxNum + 1, 0);

        for (int num : nums) {
            dp[num] += num;
        }

        for (int i = 2; i <= maxNum; i++) {
            dp[i] = max(dp[i - 1], dp[i] + dp[i - 2]);
        }

        if (maxNum >= 1)
            dp[1] = max(dp[0], dp[1]);

        return dp[maxNum];
    }
};