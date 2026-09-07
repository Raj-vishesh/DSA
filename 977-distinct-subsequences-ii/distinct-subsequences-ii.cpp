class Solution {
public:
    
    int distinctSubseqII(string s) {
        const int mod = 1e9 + 7;

        vector<int> ends_with(26 , 0);
        
        for(char c : s){
            long long sum = 0;
            for(int cnt : ends_with){
                sum = (sum + cnt ) % mod;
            }
            ends_with[c - 'a'] = (1+ sum) % mod;
        }

        long long ans = 0;

        for(int cnt : ends_with){
            ans = (ans+ cnt) %mod;
        }

        return ans;
    }
};