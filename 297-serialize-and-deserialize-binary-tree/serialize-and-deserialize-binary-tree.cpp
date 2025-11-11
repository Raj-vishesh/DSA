
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* currnode = q.front();
            q.pop();

            if(currnode == NULL) {
                s.append("#,");
            } else {
                s.append(to_string(currnode->val) + ',');
                q.push(currnode->left);
                q.push(currnode->right);
            }
        }

        return s;
    }

    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(!getline(s, str, ',')) break;
            if(str == "#") {
                node->left = NULL;
            } else {
                TreeNode* leftnode = new TreeNode(stoi(str));
                node->left = leftnode;
                q.push(leftnode);
            }

            if(!getline(s, str, ',')) break;
            if(str == "#") {
                node->right = NULL;
            } else {
                TreeNode* rightnode = new TreeNode(stoi(str));
                node->right = rightnode;
                q.push(rightnode);
            }
        }

        return root;
    }
};

// Usage example:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
