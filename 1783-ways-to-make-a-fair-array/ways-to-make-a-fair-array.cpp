class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int total_even = 0 , total_odd = 0;
        for(int i = 0 ; i < n ; i++){
            if(i %2 ==0 ) total_even += nums[i];
            else total_odd += nums[i];
        }

        int curr_even = 0 ; int curr_odd = 0;
        int cnt =0;

        for(int i = 0 ; i < n ; i++){
            if(i%2 == 0) total_even -= nums[i];
            else total_odd -= nums[i];

            if(curr_even  + total_odd == curr_odd + total_even){
                cnt++;
            }
            if(i %2 == 0) curr_even += nums[i];
            else curr_odd += nums[i];
        }
        return cnt;
    }
};