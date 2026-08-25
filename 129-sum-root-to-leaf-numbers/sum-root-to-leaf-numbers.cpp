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


    int sum(TreeNode* root , int currentSum){

        if(root == nullptr){
            return 0;
        }

        currentSum = currentSum *10 + root->val;
        if(root->left == nullptr && root->right == nullptr){
            return currentSum;
        }

        
        int leftSum = sum(root->left , currentSum);
        int rightSum = sum(root->right , currentSum);

        return leftSum + rightSum;
        
    }
    

    int sumNumbers(TreeNode* root) {
        
       return  sum(root  , 0 );
    
    }
};