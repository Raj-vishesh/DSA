class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        int rem = total % p;

        if(rem == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        long long pref = 0;
        int ans = n;

        for(int i = 0; i < n; i++) {
            pref += nums[i];

            int cur = pref % p;
            int need = (cur - rem + p) % p;

            if(mp.find(need) != mp.end()) {
                ans = min(ans, i - mp[need]);
            }

            mp[cur] = i;
        }

        return ans == n ? -1 : ans;
    }
};