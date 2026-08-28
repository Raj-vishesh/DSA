class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        // Count characters
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Check whether a palindrome is possible
        int odd = 0;
        int mid = -1;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                odd++;
                mid = i;
            }
        }

        if (odd > 1)
            return "";

        // Only half of every character goes into the left half
        for (int i = 0; i < 26; i++) {
            freq[i] /= 2;
        }

        int half = n / 2;

        string ans(n, 'a');

        // Build palindrome from its left half
        auto makePalindrome = [&]() {

            if (mid != -1)
                ans[half] = char('a' + mid);

            for (int i = 0; i < half; i++) {
                ans[n - 1 - i] = ans[i];
            }
        };

        int pos = 0;

        /*
            Try to keep the left half equal to target.
        */
        while (pos < half) {

            int ch = target[pos] - 'a';

            if (freq[ch] == 0)
                break;

            ans[pos] = target[pos];
            freq[ch]--;

            pos++;
        }

        /*
            We matched the entire left half.
            The palindrome is completely determined now.
        */
        if (pos == half) {

            makePalindrome();

            if (ans > target)
                return ans;
        }

        /*
            We couldn't get a valid answer by staying equal.

            Now backtrack and try to make one position
            bigger than target.

            We start from the RIGHTMOST position because
            that gives the smallest possible answer.
        */
        while (true) {

            if (pos < half) {

                int need = target[pos] - 'a' + 1;

                // Find the smallest available character
                // greater than target[pos]
                for (int ch = need; ch < 26; ch++) {

                    if (freq[ch] == 0)
                        continue;

                    ans[pos] = char('a' + ch);
                    freq[ch]--;

                    /*
                        After making the first greater character,
                        fill everything after it with the
                        smallest possible characters.
                    */
                    int idx = pos + 1;

                    for (int c = 0; c < 26; c++) {

                        while (freq[c] > 0) {
                            ans[idx++] = char('a' + c);
                            freq[c]--;
                        }
                    }

                    makePalindrome();

                    return ans;
                }
            }

            /*
                No bigger character possible here.

                Go one position back and restore the character
                we had taken from target.
            */
            if (pos == 0)
                return "";

            pos--;

            freq[target[pos] - 'a']++;
        }
    }
};