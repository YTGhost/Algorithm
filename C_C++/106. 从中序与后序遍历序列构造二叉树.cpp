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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(0, inorder.size()-1, 0, postorder.size()-1, inorder, postorder);
    }
    TreeNode* build(int inleft, int inright, int posleft, int posright, vector<int>& inorder, vector<int>& postorder){
        if(inleft > inright || posleft > posright)  return NULL;
        int rootat = inleft;
        while(inorder[rootat] != postorder[posright])   rootat++;
        TreeNode* root = new TreeNode(postorder[posright]);
        int temp = inright-rootat;
        root->left = build(inleft, rootat-1, posleft, posright-temp-1, inorder, postorder);
        root->right = build(rootat+1, inright, posright-temp, posright-1, inorder, postorder);
        return root;
    }
};