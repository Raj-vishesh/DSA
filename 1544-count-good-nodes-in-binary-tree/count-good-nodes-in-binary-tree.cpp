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

    int dfs(TreeNode* root , int maxsoFar){
        int cnt = 0;

        if(root == nullptr) return 0;
        if(root->val >= maxsoFar){
            cnt = 1;
            maxsoFar = root->val;
        }

        cnt+= dfs(root->left ,maxsoFar );
        cnt+= dfs(root->right , maxsoFar);

        return cnt;
    }


    int goodNodes(TreeNode* root) {
        
      return   dfs(root , root->val);

    }
};