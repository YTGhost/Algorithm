/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* flipBinaryTree(Node* root, Node * leaf) {
        auto node = leaf;
        auto parent = node->parent;
        while(node != root) {
            auto grant = parent->parent;
            if(node->left) {
                node->right = node->left;
            }
            node->left = parent;
            parent->parent = node;
            if(parent->left == node) {
                parent->left = NULL;
            }
            if(parent->right == node) {
                parent->right = NULL;
            }
            node = parent;
            parent = grant;
        }
        leaf->parent = NULL;
        return leaf;
    }
};