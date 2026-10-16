class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0 ;
        int n = s.size();
        unordered_set<char> seen;

        int max_len = 0;

        for(int j = 0 ; j < n ; j++){

            while(seen.find(s[j]) != seen.end()){
                seen.erase(s[i]);
                i++;
            }

            seen.insert(s[j]);

            max_len = max(max_len , j- i +1);
        }
        return max_len;
    
    }

};