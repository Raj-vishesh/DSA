class Solution {
public:
    bool isPalindrome(string s) {
        
        string cleaned = "";

        for(char c : s){
            if(isalnum(c)){     //     isalnum()  ->   is used to check for function , punctuation and spaces and numbers
                cleaned += tolower(c);              // tolower(c) ->    is used to conver upperCase to lowercase
            }
        }

        string p = cleaned;

        

        reverse(cleaned.begin() ,cleaned.end());

        if( cleaned== p) return true ;
        else return false;
    }
};