class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s;

        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        string temp = s + "#" + rev_s;
        int m = temp.length();
        vector<int> lps(m, 0);

        for (int i = 1; i < m; i++) {
            int j = lps[i - 1];
            while (j > 0 && temp[i] != temp[j]) {
                j = lps[j - 1];
            }
            if (temp[i] == temp[j]) {
                j++;
            }
            lps[i] = j;
        }

        
        int longest_pal_len = lps.back();
        
        string remaining = s.substr(longest_pal_len);
        reverse(remaining.begin(), remaining.end());
        
        return remaining + s;
    }
};