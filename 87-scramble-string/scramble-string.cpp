class Solution {
public:
    unordered_map<string, bool> memo;

    bool isScramble(string s1, string s2) {
        int n = s1.length();
        
        // Base Case: Identity
        if (s1 == s2) return true;
        
        // Pruning: If character counts don't match, they can't be scrambled
        string key = s1 + "_" + s2;
        if (memo.count(key)) return memo[key];
        
        vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return memo[key] = false;
        }

        for (int i = 1; i < n; i++) {
            // Case 1: No swap at this level
            // s1: [left_i][right_n-i]  s2: [left_i][right_n-i]
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                isScramble(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }

            // Case 2: Swap occurred at this level
            // s1: [left_i][right_n-i]  s2: [right_n-i][left_i]
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) && 
                isScramble(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }
};