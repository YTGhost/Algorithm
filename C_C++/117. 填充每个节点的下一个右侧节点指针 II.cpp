/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        while(q.size()) {
            int cnt = q.size();
            for(int i = 0; i < cnt; i++) {
                auto a = q.front();
                q.pop();
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
                if(i != cnt - 1) {
                    auto b = q.front();
                    a->next = b;
                }
            }
        }
        return root;
    }
};

// 空间O(1)
class Solution {
public:
    void handle(Node* &last, Node* &p, Node* &nextStart) {
        if(last) last->next = p;
        if(!nextStart) nextStart = p;
        last = p;
    }

    Node* connect(Node* root) {
        if(!root) return NULL;
        Node* start = root;
        while(start) {
            Node *last = NULL, *nextStart = NULL;
            for(Node *p = start; p != NULL; p = p->next)
            {
                if(p->left) handle(last, p->left, nextStart);
                if(p->right) handle(last, p->right, nextStart);
            }
            start = nextStart;
        }
        return root;
    }
};

// 空间O(n)
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                auto node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                node->next = i == size - 1 ? NULL : q.front();
            }
        }
        return root;
    }
};