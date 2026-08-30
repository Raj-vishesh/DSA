class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mid = n/2;
        if(n == 1) return 1;
        int maxi = *max_element(nums.begin() , nums.end());
        int mini = *min_element(nums.begin() ,nums.end());
        int maxiInd, miniInd;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] == maxi) {
                maxiInd = i;
            }
            else if(nums[i] == mini){
                miniInd = i;
            }
        }

        if(maxiInd < mid && miniInd < mid){
            return max(miniInd , maxiInd) + 1;
        }
        else if(maxiInd >= mid && miniInd >= mid){
            return n- min(maxiInd , miniInd);
        }

        
        else {
            int bothLeft = max(maxiInd, miniInd) + 1;
            int bothRight = n - min(maxiInd, miniInd);

            int oneEach;

            if (maxiInd < mid) {
                
                oneEach = maxiInd + 1 + (n - miniInd);
            }
            else {
               
                oneEach = miniInd + 1 + (n - maxiInd);
            }

            return min({bothLeft, bothRight, oneEach});
        }

    }
};