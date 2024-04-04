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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> res;
        if(n % 2 == 0) {
            return res;
        }
        if(n == 1) {
            res = {new TreeNode(0)};
            return res;
        }
        for(int i = 1; i < n; i+=2) {
            auto leftNodes = allPossibleFBT(i);
            auto rightNodes = allPossibleFBT(n - i - 1);
            for(auto left : leftNodes) {
                for(auto right : rightNodes) {
                    res.push_back(new TreeNode(0, left, right));
                }
            }
        }
        return res;
    }
};