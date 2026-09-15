class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);

        int prod = 1;
        int zeroCount = 0;

        // Total product of non-zero elements
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeroCount++;
            } else {
                prod *= nums[i];
            }
        }

        for (int i = 0; i < n; i++) {

            // More than one zero
            if (zeroCount > 1) {
                answer[i] = 0;
            }

            // Exactly one zero
            else if (zeroCount == 1) {
                if (nums[i] == 0)
                    answer[i] = prod;
                else
                    answer[i] = 0;
            }

            // No zero
            else {
                answer[i] = prod / nums[i];
            }
        }

        return answer;
    }
};