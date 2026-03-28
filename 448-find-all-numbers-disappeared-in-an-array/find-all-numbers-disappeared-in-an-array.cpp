class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1 , 0);
        for(auto x : nums){
            freq[x]++;
        }
        vector<int> ans;

        for(int i = 1 ; i <= n ; i++){
            if(freq[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};