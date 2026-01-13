class Solution {
public:
    int maxSum = 0;

    struct Info {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };

    Info solve(TreeNode* root) {
        if (!root) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        Info left = solve(root->left);
        Info right = solve(root->right);

        Info curr;

        if (left.isBST && right.isBST &&
            root->val > left.maxVal &&
            root->val < right.minVal) {

            curr.isBST = true;
            curr.sum = left.sum + right.sum + root->val;
            curr.minVal = min(root->val, left.minVal);
            curr.maxVal = max(root->val, right.maxVal);

            maxSum = max(maxSum, curr.sum);
        } else {
            curr.isBST = false;
            curr.sum = 0;
            curr.minVal = INT_MIN;
            curr.maxVal = INT_MAX;
        }

        return curr;
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};
