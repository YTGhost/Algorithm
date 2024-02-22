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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if(preorder.empty()) return NULL;
        if(preorder.size() == 1) return new TreeNode(preorder[0]);
        int leftSize = ranges::find(postorder, preorder[1]) - postorder.begin() + 1;
        vector<int> pre1 = vector<int>(preorder.begin() + 1, preorder.begin() + 1 + leftSize);
        vector<int> pre2 = vector<int>(preorder.begin() + 1 + leftSize, preorder.end());
        vector<int> pos1 = vector<int>(postorder.begin(), postorder.begin() + leftSize);
        vector<int> pos2 = vector<int>(postorder.begin() + leftSize, postorder.end() - 1);
        TreeNode* left = constructFromPrePost(pre1, pos1);
        TreeNode* right = constructFromPrePost(pre2, pos2);
        return new TreeNode(preorder[0], left, right);
    }
};