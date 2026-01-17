class Solution {
public:
    bool isPalindrome(string s) {

        // string cleaned = "";

        // for (char c : s) {
        //     if (isalnum(
        //             c)) { //     isalnum()  ->   is used to check for function ,
        //                   //     punctuation and spaces and numbers
        //         cleaned += tolower(c); // tolower(c) ->    is used to conver
        //                                // upperCase to lowercase
        //     }
        // }

       

        // string p = cleaned;

        // reverse(cleaned.begin(), cleaned.end());

        // if (cleaned == p)
        //     return true;
        // else
        //     return false;




        int i = 0; 
        int j = s.length() - 1 ;

        while(i <= j){
            
            char left = s.at(i);

            char right = s.at(j);


            if(!isalnum(left)){
                i++;
                continue;
            }

            if(!isalnum(right)){
                j--;
                continue;
            }

            if(tolower(left)  != tolower(right)){
                return false;
                
            }

            i++;

            j--;

        }



        return true;



    }
};