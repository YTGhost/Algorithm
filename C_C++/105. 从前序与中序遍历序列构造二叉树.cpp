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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(0, preorder.size()-1, 0, inorder.size()-1, preorder, inorder);
    }
    TreeNode* build(int preleft, int preright, int inleft, int inright, vector<int>& preorder, vector<int>& inorder){
        if(preleft > preright || inleft > inright)  return NULL;
        int rootat = inleft;
        while(inorder[rootat] != preorder[preleft])    rootat++;
        TreeNode* root = new TreeNode(preorder[preleft]);
        int temp = rootat-inleft;
        root->left = build(preleft+1, preleft+temp, inleft, rootat-1, preorder, inorder);
        root->right = build(preleft+temp+1, preright, rootat+1, inright, preorder, inorder);
        return root;
    }
};