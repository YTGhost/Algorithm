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
    void dfs(TreeNode* root, vector<int>& list) {
        if(!root) return;
        dfs(root->left, list);
        list.push_back(root->val);
        dfs(root->right, list);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1, list2;
        dfs(root1, list1);
        dfs(root2, list2); 
        int n = list1.size(), m = list2.size();
        vector<int> res;
        int i = 0, j = 0;
        while(i < n || j < m) {
            int a = i < n ? list1[i] : INT_MAX;
            int b = j < m ? list2[j] : INT_MAX;
            if(a <= b) {
                res.push_back(a);
                i++;
            } else {
                res.push_back(b);
                j++;
            }
        }
        return res;
    }
};