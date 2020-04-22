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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return ans;
        q.push(root);
        int count;
        while(!q.empty())
        {
            count = q.size();
            int maxValue = INT_MIN;
            for(int i = 0; i < count; i++)
            {
                maxValue = max(maxValue, q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            ans.push_back(maxValue);
        }
        return ans;
    }
};