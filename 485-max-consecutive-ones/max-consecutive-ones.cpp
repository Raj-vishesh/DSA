class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int max_1 = 0;
        int cnt_1 = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 1) {
                cnt_1++;
                max_1 = max(max_1 , cnt_1);
            }
            else{
                cnt_1 = 0;
            }
        }
        return max_1;
    }
};