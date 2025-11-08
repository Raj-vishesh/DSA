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
    TreeNode* createTree(vector<int> &postorder, int poststart, int postend, 
                         vector<int> &inorder, int instart, int inend, 
                         map<int, int> &mp) {

        // Base case
        if (poststart > postend || instart > inend)
            return nullptr;

        // Step 1: Root from postorder end
        TreeNode* root = new TreeNode(postorder[postend]);

        // Step 2: Find root index in inorder
        int inroot = mp[root->val];
        int numsLeft = inroot - instart;

        // Step 3: Build right subtree first
        root->right = createTree(postorder, poststart + numsLeft, postend - 1,
                                 inorder, inroot + 1, inend, mp);

        // Step 4: Build left subtree
        root->left = createTree(postorder, poststart, poststart + numsLeft - 1,
                                inorder, instart, inroot - 1, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return createTree(postorder, 0, postorder.size() - 1,
                          inorder, 0, inorder.size() - 1, mp);
    }
};
