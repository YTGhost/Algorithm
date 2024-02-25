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
    unordered_map<int, int> hash;
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        if(pl > pr) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[pl]);
        int k = hash[preorder[pl]];
        root->left = dfs(preorder, inorder, pl + 1, k - il + pl, il, k - 1);
        root->right = dfs(preorder, inorder, k - il + pl + 1, pr, k + 1, ir);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        for(int i = 0; i < n; i++) {
            hash[inorder[i]] = i;
        }
        return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};