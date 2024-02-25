/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if(!root) return;
            dfs(root->left);
            res.push_back(root->val);
            dfs(root->right);
        };
        dfs(root);
        return res;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        function<void(TreeNode* root)> dfs = [&](TreeNode* root) {
            if(!root) return;
            dfs(root->left);
            res.push_back(root->val);
            dfs(root->right);
        };
        dfs(root);
        return res;
    }
};
// 迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        auto cur = root;
        stack<TreeNode*> s;
        while(cur || !s.empty())
        {
            if(cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                auto t = s.top();
                s.pop();
                res.emplace_back(t->val);
                cur = t->right;
            }
        }
        return res;
    }
};

// 递归
class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root){
            inorderTraversal(root->left);
            res.push_back(root->val);
            inorderTraversal(root->right);
        }
        return res;
    }
};