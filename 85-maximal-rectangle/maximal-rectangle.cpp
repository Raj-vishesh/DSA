class Solution {
public:

    int largehistogramArea(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        int maxA= 0 ;
        for(int i = 0; i<=n ; i++){
            while(!st.empty() && ( i == n  || arr[st.top()] >= arr[i])){
                int height = arr[st.top()];
                st.pop();
            
            int width ; 
            if(st.empty()) width = i;
            else
            width  = i - st.top() - 1;
            maxA = max(maxA , height * width );
        }
        st.push(i);
    }

    return maxA;
        
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m  = matrix[0].size();
        int max_area = 0;

        vector<int> height(m , 0);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == '1'){
                    height[j]++;
                }
                else{
                    height[j] = 0;
                }
            }

            int area = largehistogramArea(height);
            max_area = max(area , max_area);

        }

        return max_area;


        // int n = matrix.size();
        // int m = matrix[0].size();
        // int maxArea = 0;
        // vector<vector<int>> psum(n, vector<int>(m, 0));
        // for(int j = 0 ; j< m ; j++){
        //     int sum = 0;
        //     for(int i = 0 ; i< n; i++){
                
        //         if(matrix[i][j] == '1') sum++;
        //         else sum = 0;
        //         psum[i][j] = sum;
        //     }
        // }

        // for(int i = 0; i < n ; i++){
        //      maxArea = max(maxArea , largehistogramArea(psum[i]));
        // }
        //     return maxArea;
    }
};