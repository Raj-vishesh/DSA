class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> cumXor(n , 0);
        cumXor[0] = arr[0];
        for(int i =1 ; i < n ; i++){
            cumXor[i]= arr[i] ^ cumXor[i-1];
        }
        vector<int> result;
        for(auto query : queries){
            int l = query[0];
            int r=  query[1];

            int xor_val = cumXor[r] ^ (l == 0 ? 0 : cumXor[l-1]);
            result.push_back(xor_val);
            
        }
        return result;
    }
};