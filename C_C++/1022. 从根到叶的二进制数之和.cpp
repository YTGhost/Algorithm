class Solution {
public:
    int sumRootToLeaf(TreeNode* root, int sub = 0) {
        if (!root) return 0;
        // 每增加一个节点，上一个节点就外前移一位。
        // 而当前的值只可能是0 1 与十进制的0 1 是一个意思就直接累加
        sub = (sub << 1) + root->val;
        return root->left == root->right ? sub :
            sumRootToLeaf(root->left, sub) + sumRootToLeaf(root->right, sub);
    }
};