class Solution {
public:


    string printlcs(string x , string y, int n , int m){
        int dp[n+1][m+1];

        for(int i= 0 ; i < n+1 ; i++){
            for(int j = 0 ; j < m+1; j++){
                if(i == 0  || j == 0) dp[i][j]= 0;
            }
        }

        for(int i = 1 ; i < n+1; i++){
            for(int j = 1 ; j < m+1 ; j++){
                if(x[i-1] == y[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        int i = n , j = m ; string s  = "";
        while(i > 0  && j > 0){
            if(x[i-1] == y[j-1]){
                s.push_back(x[i-1]);
                i--;j--;
            }
            else{
                if(dp[i-1][j]  >  dp[i][j-1]){
                    i--;
                }
                else{
                    j--;
                }
            }
        }
        reverse(s.begin() , s.end());

        return s ;



    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length() ;
        int m = str2.length();

        string lcs = printlcs(str1 , str2 , n , m);
        string total = "";
        int i = 0 ; int j = 0;
        for(char c : lcs){
            while(i < n && str1[i] != c){
                total.push_back(str1[i]);
                i++;
            }
            while( j < m && str2[j] != c){
                total.push_back(str2[j]);
                j++;
            }
            total.push_back(c);
            i++;
            j++;

        }
        while(i < n){
            total.push_back(str1[i]);
            i++;
        }
        while( j < m ){
            total.push_back(str2[j]);
            j++;
        }
        
        return total;
        

    }
};