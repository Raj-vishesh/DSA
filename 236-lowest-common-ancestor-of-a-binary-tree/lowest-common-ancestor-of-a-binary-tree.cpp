/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int fun(TreeNode* node , TreeNode* p , TreeNode* q , TreeNode* &ans){

        
        if(node == nullptr) {
            return 0;
        }

        int left = fun(node->left , p , q , ans);
        int right = fun(node->right , p , q, ans);
        int self = 0;
        if(node ==  p || node == q){
            self = 1;
        }

        int total = left + right + self;

        if(total == 2 && ans == nullptr){
            ans = node;
        }

        return total;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        fun(root , p , q ,ans);
        return ans;
    }
};