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
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(!root) return res;
        function<void(Node*)> dfs = [&](Node* root) {
            if(!root) return;
            for(auto child : root->children) {
                dfs(child);
            }
            res.push_back(root->val);
        };
        dfs(root);
        return res;
    }
};

class Solution {
public:
    vector<int> res;
    void dfs(Node* root) {
        if(!root) return;
        for(auto child : root->children) {
            dfs(child);
        }
        res.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        dfs(root);
        return res;
    }
};

class Solution {
public:
    vector<int> a;
    vector<int> postorder(Node* root) {
        if(root){
            vector<Node*>::iterator it;
            for(it = root->children.begin(); it != root->children.end(); it++){
                postorder(*it);
            }
            a.insert(a.end(), root->val);
        }
        return a;
    }
};