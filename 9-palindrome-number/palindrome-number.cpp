class Solution {
public:
    bool isPalindrome(int x) {
        string p = to_string(x);
        string q = p;
        reverse(p.begin() , p.end());
        if(p == q) return true;
        else  return false;
    }
};