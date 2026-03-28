class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n+1 ,0);
        int duplicate = -1;
        int missing = -1;

        for(int x: nums){
            count[x]++;
        }

        for(int i = 1 ; i <= n ; i++){
            if(count[i] == 2){
                duplicate = i;
            }

            else if(count[i] ==  0){
                missing = i;
            }
        }

        return {duplicate , missing};


        
    }
};