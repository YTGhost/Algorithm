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
        if(postorder.empty()) return NULL;
        int n = postorder.size();
        int leftSize = ranges::find(inorder, postorder[n - 1]) - inorder.begin();
        vector<int> ino1(inorder.begin(), inorder.begin() + leftSize);
        vector<int> ino2(inorder.begin() + 1 + leftSize, inorder.end());
        vector<int> pos1(postorder.begin(), postorder.begin() + leftSize);
        vector<int> pos2(postorder.begin() + leftSize, postorder.end() - 1);
        TreeNode* left = buildTree(ino1, pos1);
        TreeNode* right = buildTree(ino2, pos2);
        return new TreeNode(postorder[n - 1], left, right);
    }
};

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