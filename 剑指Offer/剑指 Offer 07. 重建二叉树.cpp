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
    vector<int> pre, ino;
    unordered_map<int, int> map;
    TreeNode* dfs(int pl, int pr, int il, int ir){
        if(pl > pr || il > ir) return NULL;
        auto root = new TreeNode(pre[pl]);
        int k = map[root->val];
        auto left = dfs(pl+1, pl+k-il, il, k-1);
        auto right = dfs(pr-ir+k+1, pr, k+1, ir);
        root->left = left, root->right = right;
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder, ino = inorder;
        for(int i = 0; i < ino.size(); i++) map[ino[i]] = i;
        return dfs(0, pre.size()-1, 0, ino.size()-1);
    }
};