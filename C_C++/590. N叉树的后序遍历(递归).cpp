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