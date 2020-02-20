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
    int maxDepth(Node* root) {
        if(!root){
            return 0;
        }
        vector<Node*>::iterator it;
        int max = 0;
        for(it = root->children.begin(); it != root->children.end(); it++){
            max = std::max(maxDepth(*it), max);
        }
        return ++max;
    }
};