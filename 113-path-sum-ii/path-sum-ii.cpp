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

    void funcheck(TreeNode* root , int targetSum , vector<int> &ans , vector<vector<int>> &res){

        if(root == nullptr){
            return ;
        }
        ans.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            if(root->val == targetSum) {
                res.push_back(ans);
            }

        }
        else{
            int remSum = targetSum - root->val;

            funcheck(root->left , remSum , ans ,res);
            funcheck(root->right , remSum , ans , res);
        }

        ans.pop_back();

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> ans;
        
        funcheck(root , targetSum , ans , res);

        return res;
    }
};