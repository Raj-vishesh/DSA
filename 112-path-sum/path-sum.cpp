/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return false;
        }
        
        
        if(root->left == NULL && root->right == NULL ){
            if(root->val == targetSum) return true;
        }



            int remainSum = targetSum - root->val;
           bool leftpath = hasPathSum(root->left , remainSum);
           bool rightpath = hasPathSum(root->right , remainSum);
        
        return leftpath|| rightpath;

    }
};