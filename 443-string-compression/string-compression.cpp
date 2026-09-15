class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;
        for(int i = 0 ; i < n ; i++){
            int cnt = 1;

            while( i + 1 < n && chars[i] == chars[i+1]){
                cnt++;
                i++;
            }

            chars[idx++] = chars[i];

            if(cnt > 1){
                string s = to_string(cnt);

                for(char c : s){
                    chars[idx++] = c;
                }
            }
        }

        return idx;
    }
};