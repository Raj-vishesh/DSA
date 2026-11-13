class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }

        long long total = 0;
        long long curr_op = 0;
        deque<int> dq; // Stores indices of elements in strictly decreasing order from front to back
        int left = n - 1;

        for (int right = n - 1; right >= 0; --right) {
            // Pop elements smaller than nums[right] and undo their previously added cost
            while (!dq.empty() && nums[dq.back()] < nums[right]) {
                int curr_idx = dq.back();
                dq.pop_back();
                int next_idx = dq.empty() ? left + 1 : dq.back();
                
                // Remove the cost previously added for the range [curr_idx, next_idx - 1]
                long long count = next_idx - curr_idx;
                long long prev_target_sum = count * nums[curr_idx];
                long long actual_sum = pref[next_idx] - pref[curr_idx];
                curr_op -= (prev_target_sum - actual_sum);
            }

            // Calculate the new cost for nums[right] covering up to the next greater element (or left)
            int next_idx = dq.empty() ? left + 1 : dq.back();
            long long count = next_idx - right;
            long long new_target_sum = count * nums[right];
            long long actual_sum = pref[next_idx] - pref[right];
            curr_op += (new_target_sum - actual_sum);

            dq.push_back(right);

            // Shrink the window from the right side (variable named `left`) while operations exceed k
            while (left >= right && curr_op > k) {
                // The element at `left` is currently raised to match `nums[dq.front()]`
                curr_op -= (nums[dq.front()] - nums[left]);
                if (dq.front() == left) {
                    dq.pop_front();
                }
                left--;
            }

            total += (left - right + 1);
        }

        return total;
    }
};
