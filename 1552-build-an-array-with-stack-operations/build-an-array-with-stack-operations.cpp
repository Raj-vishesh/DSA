class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;

        int target_idx = 0;

        for(int i = 1 ; i <= n && target_idx < target.size(); i++){
            result.push_back("Push");
            if(target[target_idx] == i){
                
                target_idx++;
            }
            else{
                result.push_back("Pop");
            }
        }

        return result;

    }
};