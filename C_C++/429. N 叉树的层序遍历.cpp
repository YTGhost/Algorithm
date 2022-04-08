/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> res;
        if(!root) return res;
        q.push(root);
        while(!q.empty()) {
            int cnt = q.size();
            vector<int> level(cnt);
            for(int i = 0; i < cnt; i++) {
                auto t = q.front();
                q.pop();
                level[i] = t->val;
                for(int j = 0; j < t->children.size(); j++) {
                    q.push(t->children[j]);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};