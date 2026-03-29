class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n = s1.size();
        bool checkEven = (s1[0] == s2[0] && s1[2] == s2[2]) || (s1[0] == s2[2] && s1[2] == s2[0] );

        bool checkOdd = (s1[1] == s2[1] && s1[3] == s2[3]) || (s1[1] == s2[3] && s1[3] == s2[1] );

        return checkEven && checkOdd;
    }
};