class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        string result(n + m - 1, '\0');
        vector<bool> fixed(n + m - 1, false);

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (result[i + j] != '\0' && result[i + j] != str2[j]) return "";
                    result[i + j] = str2[j];
                    fixed[i + j] = true;
                }
            }
        }

        for (int i = 0; i < n + m - 1; i++) {
            if (result[i] == '\0') result[i] = 'a';
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (result[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    bool changed = false;

                    for (int j = m - 1; j >= 0; j--) {
                        if (!fixed[i + j]) {
                            char nextChar = result[i + j] + 1;
                            if (nextChar == str2[j]) nextChar++;
                            
                            if (nextChar <= 'z') {
                                result[i + j] = nextChar;
                                changed = true;

                                for (int k = i + j + 1; k < n + m - 1; k++) {
                                    if (!fixed[k]) result[k] = 'a';
                                }
                                break;
                            }
                        }
                    }
                    
                    if (!changed) return "";
                    i = max(-1, i - m); 
                }
            }
        }

        return result;
    }
};