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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if(!root) return;
            res.push_back(root->val);
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);
        return res;
    }
};
// 迭代
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            auto t = s.top();
            s.pop();
            res.emplace_back(t->val);
            if(t->right) s.push(t->right);
            if(t->left) s.push(t->left);
        }
        return res;
    }
};
// 递归
class Solution {
public:
    vector<int> a;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root){
            a.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right); 
        }
        return a;
    }
};