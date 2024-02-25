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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string res = "";
        if(!root) return res;
        q.push(root);
        res += to_string(root->val) + ",";
        while(!q.empty()) {
            auto item = q.front();
            q.pop();
            if(item->left) {
                q.push(item->left);
                res += to_string(item->left->val) + ",";
            } else {
                res += " ,";
            }
            if(item->right) {
                q.push(item->right);
                res += to_string(item->right->val) + ",";
            } else {
                res += " ,";
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        int num, idx = 0;
        string t = "";
        while(data[idx] != ',') {
            t += data[idx++];
        }
        num = stoi(t);
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(num);
        q.push(root);
        idx++;
        while(idx < data.length()) {
            TreeNode* node = q.front();
            q.pop();
            string t = "";
            while(data[idx] != ',') t += data[idx++];
            if(t != " "){
                num = stoi(t);
                TreeNode* left = new TreeNode(num);
                node->left = left;
                q.push(left);
            }
            idx++;
            t = "";
            while(data[idx] != ',') t += data[idx++];
            if(t != " "){
                num = stoi(t);
                TreeNode* right = new TreeNode(num);
                node->right = right;
                q.push(right);
            }
            idx++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));