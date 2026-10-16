class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long max_sum = 0;
        long long curr_sum = 0;
        unordered_set<int> s;
        int left = 0;
        for(int right = 0 ; right < n ; right++){
            while(s.find(nums[right]) != s.end()){
                s.erase(nums[left]);
                curr_sum -= nums[left];
                left++;
            }
            s.insert(nums[right]);
            curr_sum += nums[right];

            if(right - left +1 == k){
                max_sum = max(max_sum , curr_sum);

                s.erase(nums[left]);
                curr_sum -= nums[left];
                left++;
            }
        }

        return max_sum;


    }
};