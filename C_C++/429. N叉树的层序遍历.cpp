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
        vector<vector<int>> res;
        if(!root) return res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int cnt = q.size();
            vector<int> vals(cnt);
            for(int i = 0; i < cnt; i++) {
                auto node = q.front();
                q.pop();
                vals[i] = node->val;
                for(auto child : node->children) {
                    q.push(child);
                }
            }
            res.push_back(vals);
        }
        return res;
    }
};

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

class Solution {
public:
    vector<vector<int>> a;
    queue<Node*> q;
    vector<vector<int>> levelOrder(Node* root) {
        if(!root){
            return a;
        }
        q.push(root);
        vector<int> temp1(1, root->val);
        a.insert(a.end(), temp1);
        int number;
        while(!q.empty()){
            number = q.size();
            vector<int> temp2;
            for(int i = 0; i<number; i++){
                Node* t = q.front();
                q.pop();
                vector<Node*>::iterator it;
                for(it = t->children.begin(); it != t->children.end(); it++){
                    q.push(*it);
                    temp2.push_back((*it)->val);
                }
            }
            if(!temp2.empty()){
                a.push_back(temp2);
            }
        }
        return a;
    }
};