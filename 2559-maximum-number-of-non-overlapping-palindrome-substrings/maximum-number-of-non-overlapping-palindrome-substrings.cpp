class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> isPal(n , vector<bool> (n , false));
        
        for(int len = 1 ; len <= n ; len++){
            for(int i = 0 ; i <= n - len ; i++){ 
                int j = i + len - 1;
                if(s[i] == s[j]){
                    if(len <= 2) {
                        isPal[i][j] = true;
                    } else {
                        isPal[i][j] = isPal[i+1][j-1];
                    }
                }
            }
        }

        vector<int> dp(n , 0);
        for(int i = 0 ; i < n ; i++){
            if(i > 0) dp[i] = dp[i-1];
            
            for (int j = 0; j <= i - k + 1; j++){
                if(isPal[j][i]){ 
                    int prev = (j == 0) ? 0 : dp[j-1];
                    dp[i] = max(dp[i], prev + 1);
                    
                }
            }
        }

        return dp[n-1];
    }
};