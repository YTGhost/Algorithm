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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int cnt = q.size();
            vector<int> vals;
            for(int i = 0; i < cnt; i++) {
                auto node = q.front();
                q.pop();
                vals.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(vals);
        }
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int cnt = q.size();
            vector<int> t(cnt);
            for(int i = 0; i < cnt; i++) {
                auto node = q.front();
                q.pop();
                t[i] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(t);
        }
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> a;
    queue<TreeNode*> q;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return a;
        }
        q.push(root);
        vector<int> temp1(1, root->val);
        a.insert(a.end(), temp1);
        int number;
        while(!q.empty()){
            number = q.size();
            vector<int> temp2;
            for(int i = 0; i<number; i++){
                TreeNode* t = q.front();
                q.pop();
                if(t->left){
                    q.push(t->left);
                    temp2.push_back(t->left->val);
                }
                if(t->right){
                    q.push(t->right);
                    temp2.push_back(t->right->val);
                }
            }
            if(!temp2.empty()){
                a.push_back(temp2);
            }
        }
        return a;
    }
};