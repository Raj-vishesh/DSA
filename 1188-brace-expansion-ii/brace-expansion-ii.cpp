class Solution {
public:
    set<string> parseExpression(string& s, int& i) {
        set<string> result = parseTerm(s, i);

        while (i < s.size() && s[i] == ',') {
            i++;
            set<string> next = parseTerm(s, i);
            result.insert(next.begin(), next.end());
        }

        return result;
    }

    set<string> parseTerm(string& s, int& i) {
        set<string> result = {""};

        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> current;

            if (s[i] == '{') {
                i++;
                current = parseExpression(s, i);
                i++;
            } else {
                current.insert(string(1, s[i]));
                i++;
            }

            set<string> temp;

            for (auto& a : result) {
                for (auto& b : current) {
                    temp.insert(a + b);
                }
            }

            result = temp;
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> result = parseExpression(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};