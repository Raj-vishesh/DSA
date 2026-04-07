class Solution {
public:
    int lcs(string p , string q , int n  , int  m ){
        vector<vector<int>> dp(n+1 , vector<int> (m+1 ,0));

        for(int i = 1 ; i < n+1; i++){
            for(int j =1 ; j < m+1 ; j++){
                if(p[i-1] == q[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1]; 
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        return dp[n][m];

    }


    int minInsertions(string s) {
        
        string p = s;
        int n = p.size();
        reverse(s.begin() , s.end());

        string q = s;
        int m = q.size();
        int to = lcs(s, p , n , m);

        return n - to;
    }
};