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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return getLcaAndDepth(root).first;
    }

private:

    pair<TreeNode* , int> getLcaAndDepth(TreeNode* root){
        if(root == nullptr){
            return{nullptr , 0};
        }

        auto left = getLcaAndDepth(root->left);
        auto right = getLcaAndDepth(root->right);
        int leftdepth = left.second;
        int rightdepth = right.second;

        int currdepth = 1+ max(leftdepth , rightdepth);

        if(rightdepth < leftdepth){
            return{left.first , currdepth};
        }
        else if(rightdepth > leftdepth){
            return{right.first , currdepth};
        }
        return{root , currdepth};
    }
};