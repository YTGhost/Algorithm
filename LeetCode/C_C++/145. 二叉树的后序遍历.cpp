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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if(!root) return;
            dfs(root->left);
            dfs(root->right);
            res.push_back(root->val);
        };
        dfs(root);
        return res;
    }
};
//迭代（）
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            auto node = s.top();
            res.emplace_back(node->val);
            s.pop();
            if(node->left) s.push(node->left);
            if(node->right) s.push(node->right);
        }
        return vector<int>(res.rbegin(), res.rend());
    }
};
// 递归
class Solution {
public:
    vector<int> a;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root){
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            a.insert(a.end(), root->val);
        }
        return a;
    }
};