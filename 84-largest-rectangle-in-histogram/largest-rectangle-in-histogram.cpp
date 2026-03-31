class Solution {
public:

//     vector<int> findnextsmaller(vector<int> &arr){
//         int n = arr.size();
//         stack<int> st;
//         vector<int> nse(n,n);
//         for(int i = n-1 ; i>= 0;i--){
//             while(!st.empty() && arr[st.top()] >= arr[i] ){
//                 st.pop();
//             }

//             if(!st.empty()){
//                 nse[i] = st.top();

//             }    
//                 st.push(i);
            
//         }
//         return nse;
//     }

//     vector<int> findprevioussmaller(vector<int> &arr){
//         int n = arr.size();
//         stack<int> st;
//         vector<int> pse(n,-1);
//         for(int i = 0 ; i< n;i++){
//             while(!st.empty() && arr[st.top()] >= arr[i] ){
//                 st.pop();
//             }

//             if(!st.empty()){
//                 pse[i] = st.top();
//                 st.push(i);
//             }
//             st.push(i);
//         }
//         return pse;
//     }    
//     int largestRectangleArea(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> nse = findnextsmaller(arr);
//         vector<int> pse = findprevioussmaller(arr);
//         int maxi = INT_MIN;
//         for(int i = 0; i<n ; i++){
//             maxi = max(maxi , arr[i] * (nse[i] - pse[i] - 1 ));
//         }
//         return maxi;
//     }
// };


 int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        int maxA = 0;
        for(int i = 0; i<=n ; i++){
            while(!st.empty() &&  (  i == n || arr[st.top()] >= arr[i])){
                int element = arr[st.top()];
                st.pop();
                int width;
                if(st.empty()) {
                    width = i;
                }
                else
                width = i - st.top() -1 ;
                maxA = max(maxA , width * element );
            }
            st.push(i);
        }
        return maxA;
     
    }
};