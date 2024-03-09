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
        if(preorder.empty()) return NULL;
        int val = preorder[0];
        auto len = ranges::find(inorder, val) - inorder.begin();
        auto pre1 = vector<int>(preorder.begin() + 1, preorder.begin() + 1 + len);
        auto pre2 = vector<int>(preorder.begin() + 1 + len, preorder.end());
        auto ino1 = vector<int>(inorder.begin(), inorder.begin() + len);
        auto ino2 = vector<int>(inorder.begin() + len + 1, inorder.end());
        auto root = new TreeNode(val);
        root->left = buildTree(pre1, ino1);
        root->right = buildTree(pre2, ino2);
        return root;
    }
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return NULL;
        int leftSize = ranges::find(inorder, preorder[0]) - inorder.begin();
        vector<int> pre1(preorder.begin() + 1, preorder.begin() + 1 + leftSize);
        vector<int> pre2(preorder.begin() + 1 + leftSize, preorder.end());
        vector<int> ino1(inorder.begin(), inorder.begin() + leftSize);
        vector<int> ino2(inorder.begin() + 1 + leftSize, inorder.end());
        TreeNode* left = buildTree(pre1, ino1);
        TreeNode* right = buildTree(pre2, ino2);
        return new TreeNode(preorder[0], left, right);
    }
};

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