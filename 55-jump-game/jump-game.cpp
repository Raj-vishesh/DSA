class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        int max_reach = 0;

        for(int i = 0 ; i < n  ;i++){

            if( i > max_reach ) return false;

            max_reach = max(max_reach , i + nums[i]);

            if(max_reach >= n-1) return true;

        }

        if(max_reach > n) return true;

        else return false;

        

    }
};