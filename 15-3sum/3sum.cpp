class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> ans;

        sort(nums.begin() , nums.end());

        for(int k = 0 ; k < n-2 ; k++){
            int i = k+1; 
            int j = n-1;

            if(k > 0 && nums[k] == nums[k-1]) continue;

            while(i < j){

                int sum = nums[i]+nums[j]+nums[k];

                if(sum == 0){
                    ans.push_back({nums[k] , nums[i], nums[j]});
                    i++; 
                    j--;


                    //  Skip Duplicates 


                    while(i < j && nums[i] == nums[i-1]) {
                        i++;
                    }

                    while(i < j && nums[j] == nums[j+1]){
                        j--;
                    }
                }

                else if(sum < 0){

                    i++;
                }

                else{
                    j--;
                }



            }
        }

        return ans;
    }
};