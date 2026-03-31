class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int total = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> left(n + 1), right(n + 1);
        for (int mask = 0; mask < (1 << n); mask++) {
            int cnt = 0, sum = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sum += nums[i];
                }
            }

            left[cnt].push_back(sum);
        }

        for (int mask = 0; mask < (1 << n); mask++) {
            int cnt = 0, sum = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sum += nums[n + i];
                }
            }

            right[cnt].push_back(sum);
        }

        for (int i = 0; i <= n; i++) {
            sort(right[i].begin(), right[i].end());
        }

        int ans = INT_MAX;

        for (int i = 0; i <= n; i++) {
            for (int leftSum : left[i]) {
                int need = total / 2 - leftSum;

                vector<int>& arr = right[n - i];

                auto it = lower_bound(arr.begin(), arr.end(), need);

                if (it != arr.end()) {
                    int sum1 = leftSum + *it;
                    int sum2 = total - sum1;
                    ans = min(ans, abs(sum1 - sum2));
                }

                if (it != arr.begin()) {
                    --it;
                    int sum1 = leftSum + *it;
                    int sum2 = total - sum1;
                    ans = min(ans, abs(sum1 - sum2));
                }
            }
        }

        return ans;
    }
};