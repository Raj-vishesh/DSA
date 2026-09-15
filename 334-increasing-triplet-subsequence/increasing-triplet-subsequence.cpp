class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return false;
        }

        int first = INT_MAX;
        int second = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            int num  = nums[i];

            if(num <= first){
                first = num;
            }
            else if(num <= second){
                second = num;
            }
            else {
                return true;
            }
        }
        return false;
    }
};