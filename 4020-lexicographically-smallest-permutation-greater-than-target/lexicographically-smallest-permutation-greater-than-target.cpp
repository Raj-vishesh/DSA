class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> f(26);
        for (char c : s) f[c - 'a']++;

        string a;

        for (int i = 0; i < s.size(); i++) {
            int x = target[i] - 'a';

            if (f[x]) {
                a += target[i];
                f[x]--;
            } else {
                int j = x + 1;
                while (j < 26 && !f[j]) j++;

                if (j < 26) {
                    a += 'a' + j;
                    f[j]--;

                    for (int k = 0; k < 26; k++)
                        while (f[k]--)
                            a += 'a' + k;

                    return a;
                }
                break;
            }
        }

        for (int i = a.size() - 1; i >= 0; i--) {
            f[a[i] - 'a']++;

            int j = target[i] - 'a' + 1;
            while (j < 26 && !f[j]) j++;

            if (j < 26) {
                string res = a.substr(0, i) + char('a' + j);
                f[j]--;

                for (int k = 0; k < 26; k++)
                    while (f[k]--)
                        res += 'a' + k;

                return res;
            }
            a.pop_back();
        }

        return "";
    }
};