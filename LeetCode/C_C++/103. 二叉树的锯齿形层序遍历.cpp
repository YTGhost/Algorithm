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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);
        while(!q.empty()) {
            int cnt = q.size();
            deque<int> list;
            for(int i = 0; i < cnt; i++) {
                auto node = q.front();
                q.pop();
                if(level % 2 == 0) {
                    list.push_back(node->val);
                } else {
                    list.push_front(node->val);
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(vector<int>{list.begin(), list.end()});
            level++;
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        bool flag = true;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            deque<int> deq;
            int n = q.size();
            while(n--) {
                auto item = q.front();
                q.pop();
                if(flag) deq.push_back(item->val);
                else deq.push_front(item->val);
                if(item->left) q.push(item->left);
                if(item->right) q.push(item->right);
            }
            res.emplace_back(vector<int>(deq.begin(), deq.end()));
            flag = !flag;
        }
        return res;
    }
};