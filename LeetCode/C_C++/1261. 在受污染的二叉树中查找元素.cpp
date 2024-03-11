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
class FindElements {
public:
    unordered_set<int> s;
    FindElements(TreeNode* root) {
        root->val = 0;
        s.insert(0);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int cnt = q.size();
            for(int i = 0; i < cnt; i++) {
                auto node = q.front();
                q.pop();
                if(node->left) {
                    node->left->val = 2 * node->val + 1;
                    s.insert(node->left->val);
                    q.push(node->left);
                }
                if(node->right) {
                    node->right->val = 2 * node->val + 2;
                    s.insert(node->right->val);
                    q.push(node->right);
                }
            }
        }
    }
    
    bool find(int target) {
        return s.contains(target);
    }
};

class FindElements {
public:
    unordered_set<int> s;
    void dfs(TreeNode* root, int val) {
        if(!root) return;
        root->val = val;
        s.insert(val);
        dfs(root->left, 2 * val + 1);
        dfs(root->right, 2 * val + 2);
    }
    FindElements(TreeNode* root) {
        dfs(root, 0);
    }
    
    bool find(int target) {
        return s.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */