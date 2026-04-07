class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;

        sort(arr.begin() , arr.end());
        int op= INT_MAX;
        for(int i = 1 ; i < n ; i++){
            int diff = arr[i] - arr[i-1];
            op = min(diff , op);
            
        }

        for(int i = 1 ; i < n ; i++){
            if(arr[i] - arr[i-1] == op){
                ans.push_back({arr[i-1] , arr[i]});
            }
        }

        return ans;

    }
};