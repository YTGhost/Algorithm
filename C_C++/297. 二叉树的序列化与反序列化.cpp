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
        string str;
        if(!root) return str;
        q.push(root);
        str += to_string(root->val) + ',';
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
                str += to_string(temp->left->val) + ',';
            }else str += " ,";
            if(temp->right){
                q.push(temp->right);
                str += to_string(temp->right->val) + ',';
            }else str += " ,";
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) return NULL;
        queue<TreeNode*> q;
        int size = data.length();
        int i = 0;
        string str;
        stringstream stream;
        int number;
        while(data[i] != ',') str += data[i++];
        stream << str;
        stream >> number;
        stream.clear();
        TreeNode* root = new TreeNode(number);
        q.push(root);
        i++;
        for(; i < data.length(); i++)
        {
            TreeNode* node = q.front();
            q.pop();
            string t;
            while(data[i] != ',') t += data[i++];
            if(t != " "){
                stream << t;
                stream >> number;
                stream.clear();
                TreeNode* left = new TreeNode(number);
                node->left = left;
                q.push(left);
            }
            i++;
            t = "";
            while(data[i] != ',') t += data[i++];
            if(t != " "){
                stream << t;
                stream >> number;
                stream.clear();
                TreeNode* right = new TreeNode(number);
                node->right = right;
                q.push(right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));