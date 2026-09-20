class Solution {
public:

    bool isVowel(char c){
        if(c == 'a' || c == 'e'|| c == 'i' || c == 'o' || c == 'u'){
            return true;

        }
        else return false;
    }


    int maxVowels(string s, int k) {
        int current_vowel = 0;
        for(int i = 0 ; i < k; i++){

            if(isVowel(s[i])){
                current_vowel++;
            }
        }

        int max_vowel = current_vowel ; 

        for(int i = k ; i < s.size() ;i++){
            if(isVowel(s[i])){
                current_vowel++;
            }
            if(isVowel(s[i-k])){
                current_vowel--;
            }
            max_vowel = max(max_vowel , current_vowel);
        }

        return max_vowel;
    }
};