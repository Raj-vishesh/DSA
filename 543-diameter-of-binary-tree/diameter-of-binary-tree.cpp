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
    int diam = 0;
    int findmax(TreeNode* node){
        if(node == nullptr){
            return 0; 
        }

        int lh = findmax(node->left);
        int rh = findmax(node->right);

        diam = max(diam , lh +rh);
        return 1+ max(lh , rh);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        findmax(root);
        return diam;

    }
};