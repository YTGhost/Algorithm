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
    void dfs(TreeNode* root, TreeNode* &pre, int &max, int &cur, vector<int>& res) {
        if(!root) return;
        dfs(root->left, pre, max, cur, res);
        if(pre) cur = (root->val == pre->val) ? cur + 1 : 1;
        if(cur == max) {
            res.emplace_back(root->val);
        } else if (cur > max) {
            res.clear();
            res.emplace_back(root->val);
            max = cur;
        }
        pre = root;
        dfs(root->right, pre, max, cur, res);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        TreeNode* pre = NULL;
        int max = 0, cur = 1;
        dfs(root, pre, max, cur, res);
        return res;
    }
};

class Solution {
public:
    vector<int> order;
    vector<int> result;
    int current = 0;
    int max = 0;
    void getOrder(TreeNode* root)
    {
        if(root)
        {
            getOrder(root->left);
            order.push_back(root->val);
            getOrder(root->right);
        }
    }
    vector<int> findMode(TreeNode* root) {
        getOrder(root);
        if(order.size() == 1)
        {
            result.push_back(order[0]);
        }
        for(int i = 1; i < order.size(); i++)
        {
            if(order[i] == order[i-1])
            {
                current++;
            }else{
                current = 0;
            }
            if(current == max)
            {
                if(i == 1 && current == 0)
                {
                    result.push_back(order[0]);
                }
                result.push_back(order[i]);
            }
            if(current > max)
            {
                max = current;
                result.clear();
                result.push_back(order[i]);
            }
        }
        return result;
    }
};