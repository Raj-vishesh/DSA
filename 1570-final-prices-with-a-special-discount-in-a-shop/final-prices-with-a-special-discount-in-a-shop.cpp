class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();

        stack<int> st;
        vector<int> result = prices;

        for(int i = 0 ; i < n ; i++){

            while(!st.empty() && prices[i] <= prices[st.top()] ){
                int previdx = st.top();
                
                st.pop();
                result[previdx]  = prices[previdx] - prices[i];
            }

            st.push(i);
        }

        return result;



        // vector<int> ans = prices;
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = i+1 ; j < n ; j++){
        //         if(prices[j] <= prices[i] ){
        //             ans[i] = (prices[i] - prices[j]);
        //             break;
        //         }
        //     }
        // }
        // return ans;
    }
};