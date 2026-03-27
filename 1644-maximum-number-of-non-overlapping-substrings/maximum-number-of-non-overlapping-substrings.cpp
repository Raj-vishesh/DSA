class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, -1), last(26);

        for (int i = 0; i < s.size(); i++) {
            int ch = s[i] - 'a';
            if (first[ch] == -1) first[ch] = i;
            last[ch] = i;
        }

        vector<pair<int, int>> v;

        for (int i = 0; i < 26; i++) {
            if (first[i] == -1) continue;

            int l = first[i], r = last[i];
            bool ok = true;

            for (int j = l; j <= r; j++) {
                int ch = s[j] - 'a';

                if (first[ch] < l) {
                    ok = false;
                    break;
                }

                r = max(r, last[ch]);
            }

            if (ok) v.push_back({l, r});
        }

        sort(v.begin(), v.end(), [&](auto &a, auto &b) {
            return a.second < b.second;
        });

        vector<string> ans;
        int end = -1;

        for (auto [l, r] : v) {
            if (l > end) {
                ans.push_back(s.substr(l, r - l + 1));
                end = r;
            }
        }

        return ans;
    }
};