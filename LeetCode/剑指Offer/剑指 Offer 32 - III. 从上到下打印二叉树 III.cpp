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
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(!root) return ans;

        q.push(root);
        int sign = 1;
        while(!q.empty())
        {
            vector<int> res;
            int count = q.size();
            while(count--)
            {
                auto t = q.front();
                q.pop();
                res.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            if(sign % 2) ans.push_back(res);
            else ans.push_back(vector<int>(res.rbegin(), res.rend()));
            sign++;
        }
        return ans;
    }
};