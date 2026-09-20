class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int prod = 1;
        int sum = 0;
        for(int i = 1 ; i <= n ; i++){
            char ch = s[i-1];
            prod =  (i * (26 - (ch - 'a')));
            sum = sum + prod;
        }

        return sum;
    }
};