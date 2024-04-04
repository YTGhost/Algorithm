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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original || original == target) {
            return cloned;
        }
        auto res = getTargetCopy(original->left, cloned->left, target);
        if(res) {
            return res;
        }
        return getTargetCopy(original->right, cloned->right, target);
    }
};

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        auto ptr = cloned;
        TreeNode *res;
        function<void(TreeNode*)> dfs = [&](TreeNode* ptr) {
            if(!ptr) {
                return;
            }
            if(ptr->val == target->val) {
                res = ptr;
            }
            if(res) {
                return;
            }
            dfs(ptr->left);
            dfs(ptr->right);
        };
        dfs(ptr);
        return res;
    }
};

class Solution {
public:
    TreeNode* res;
    void dfs(TreeNode* cloned, TreeNode* target) {
        if(!cloned) return;
        if(cloned->val == target->val) res = cloned;
        dfs(cloned->left, target);
        dfs(cloned->right, target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(cloned, target);
        return res;
    }
};