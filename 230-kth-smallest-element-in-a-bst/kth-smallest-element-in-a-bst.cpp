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

    int cnt = 0;
    int ans = -1;

    void inorder(TreeNode* root , int k ){

        if(root == NULL){
            return ;
        }

        inorder(root->left , k);
        cnt++;
        if(cnt == k){
            ans = root->val;
            return ;
        }

        inorder(root->right , k);

    }
    
    int kthSmallest(TreeNode* root, int k) {


        inorder(root , k );
        return ans;




    //     stack<TreeNode*> st;
    //     TreeNode* curr = root;
    //     while(true){
    //         while(curr != NULL){
    //             st.push(curr);
    //             curr = curr->left;
    //         }

    //         curr = st.top();
    //         st.pop();
    //         k--;

    //         if(k == 0) return curr->val;

    //         curr = curr->right;
    //     }






    }
};