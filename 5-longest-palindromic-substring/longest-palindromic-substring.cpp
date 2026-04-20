class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 1) return "";
        int start = 0, max_len = 0;

        for (int i = 0; i < s.length(); i++) {
            // Check odd length palindromes (center is s[i])
            expand(s, i, i, start, max_len);
            // Check even length palindromes (center is between s[i] and s[i+1])
            expand(s, i, i + 1, start, max_len);
        }

        return s.substr(start, max_len);
    }

private:
    void expand(const string& s, int left, int right, int& start, int& max_len) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            int current_len = right - left + 1;
            if (current_len > max_len) {
                start = left;
                max_len = current_len;
            }
            left--;
            right++;
        }
    }
};