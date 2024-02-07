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
    bool isCousins(TreeNode* root, int x, int y) {
        vector<TreeNode*> q;
        if(root->val == x || root->val == y) return false;
        q.push_back(root);
        while(!q.empty()) {
            int xIdx = -1, yIdx = -1;
            vector<TreeNode*> q2;
            for(auto fa : q) {
                if(fa->left) {
                    q2.push_back(fa->left);
                    if(fa->left->val == x) {
                        xIdx = fa->val;
                    }
                    if(fa->left->val == y) {
                        yIdx = fa->val;
                    }
                }
                if(fa->right) {
                    q2.push_back(fa->right);
                    if(fa->right->val == x) {
                        xIdx = fa->val;
                    }
                    if(fa->right->val == y) {
                        yIdx = fa->val;
                    }
                }
            }
            if(xIdx != -1 && yIdx != -1 && xIdx != yIdx) {
                return true;
            }
            q = move(q2);
        }
        return false;
    }
};

class Solution {
public:
    int deepX, deepY, fatherX, fatherY;
    void dfs(TreeNode* root, int x, int y, int deep) {
        if(!root) return;
        if(root->left) {
            if(root->left->val == x) {
                deepX = deep + 1;
                fatherX = root->val;
            }
            if(root->left->val == y) {
                deepY = deep + 1;
                fatherY = root->val;
            }
        }
        if(root->right) {
            if(root->right->val == x) {
                deepX = deep + 1;
                fatherX = root->val;
            }
            if(root->right->val == y) {
                deepY = deep + 1;
                fatherY = root->val;
            }
        }
        dfs(root->left, x, y, deep + 1);
        dfs(root->right, x, y, deep + 1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, x, y, 0);
        return deepX == deepY && fatherX != fatherY;
    }
};