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
    static const int N = 510, M = N * 4;
    int idx;
    int he[N], e[M], ne[M];
    void add(int a, int b) {
        e[idx] = b;
        ne[idx] = he[a];
        he[a] = idx++;
    }
    void dfs(TreeNode* root) {
        if(!root) return;
        if(root->left) {
            add(root->val, root->left->val);
            add(root->left->val, root->val);
            dfs(root->left);
        }
        if(root->right) {
            add(root->val, root->right->val);
            add(root->right->val, root->val);
            dfs(root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_set<int> s;
        vector<int> res;
        memset(he, -1, sizeof(he));
        dfs(root);
        queue<int> q;
        q.push(target->val);
        s.insert(target->val);
        while(!q.empty() && k >= 0) {
            int n = q.size();
            while(n--) {
                int v = q.front();
                q.pop();
                if(k == 0) {
                    res.push_back(v);
                    continue;
                }
                for(int i = he[v]; i != -1; i = ne[i]) {
                    int node = e[i];
                    if(!s.count(node)) {
                        q.push(node);
                        s.insert(node);
                    }
                }
            }
            k--;
        }
        return res;
    }
};