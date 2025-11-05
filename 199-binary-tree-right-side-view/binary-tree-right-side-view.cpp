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

    void solve(TreeNode* node , int level , vector<int> & ds){
        if(node == nullptr){
            return;
        }

        if(level == ds.size()){
            ds.push_back(node->val);
        }


            solve(node->right , level+1 , ds);

            solve(node->left , level+1, ds);
        
    }



    vector<int> rightSideView(TreeNode* root) {
        vector<int> ds;
        solve(root , 0 , ds);
        return ds;
    }
};