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
class CBTInserter {
public:
    TreeNode* root;
    queue<TreeNode*> q;
    CBTInserter(TreeNode* root) {
        this->root = root;
        q.push(root);
        while(q.front()->left && q.front()->right) {
            auto item = q.front();
            q.pop();
            q.push(item->left);
            q.push(item->right);
        }
    }
    
    int insert(int val) {
        auto item = q.front();
        auto node = new TreeNode(val);
        if(!item->left) {
            item->left = node;
        } else {
            item->right = node;
            q.pop();
            q.push(item->left);
            q.push(item->right);
        }
        return item->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */