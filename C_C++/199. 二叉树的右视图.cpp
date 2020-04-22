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
    vector<int> ans;
    queue<TreeNode*> q;
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return ans;
        q.push(root);
        int count = 1;
        while(!q.empty())
        {
            count = q.size();
            for(int i = 0; i < count; i++)
            {
                if(i == count - 1) ans.push_back(q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
        }
        return ans;
    };

};