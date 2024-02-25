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
    int sum;
    void dfs(TreeNode* root) {
        if(!root) return;
        dfs(root->right);
        int t = sum;
        sum += root->val;
        root->val += t;
        dfs(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        return root;
    }
};
class Solution {
public:
    int num;
    TreeNode* bstToGst(TreeNode* root) {
        if(!root) return root;
        bstToGst(root->right);
        root->val += num;
        num = root->val;
        bstToGst(root->left);
        return root;
    }
};

class Solution {
public:
    vector<int> a;
    int count = 0;
    void getVec(TreeNode* root){
        if(root)
        {
            getVec(root->left);
            a.push_back(root->val);
            getVec(root->right);
        }
    }

    void changeTree(TreeNode* root){
        if(root)
        {
            changeTree(root->left);
            int sum = 0;
            for(int i = count; i < a.size(); i++)
            {
                sum += a[i];
            }
            root->val = sum;
            count++;
            changeTree(root->right);
        }
    }

    TreeNode* bstToGst(TreeNode* root) {
        getVec(root);
        changeTree(root);
        return root;
    }
};