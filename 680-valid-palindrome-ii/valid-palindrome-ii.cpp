class Solution {
public:

    bool palindromeHelper(int i , int j , string s){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }

            i++;
            j--;
        }

        return true;
    }



    bool validPalindrome(string s) {
        int n = s.size();

        int i = 0 ; 
        int j = n-1;

       

        while(i < j){
            char &left = s[i];

            char &right = s[j];

            if(left != right){
                return palindromeHelper(i+1 , j , s) || palindromeHelper(i , j-1 , s);
            }

            else{
                i++;
                j--;
            }


        }

        return true;

    }
};