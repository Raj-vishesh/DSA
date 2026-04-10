class Solution {
public:
    int dp[2001];

    bool ispalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    int solve(string &s, int i, int n) {
        if (i == n) return 0;
        if (ispalindrome(s, i, n - 1)) return 0; // If the rest is already a pal, 0 more cuts
        if (dp[i] != -1) return dp[i];

        int ans = n; // Max possible cuts

        for (int j = i; j < n - 1; j++) {
            if (ispalindrome(s, i, j)) {
                // We found a palindrome from i to j, so we cut after j
                ans = min(ans, 1 + solve(s, j + 1, n));
            }
        }
        return dp[i] = ans;
    }

    int minCut(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, s.size());
    }
};