/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* pre = NULL;
    Node* flatten(Node* head) {
        Node* p = head;
        dfs(head);
        return p;
    }
    Node* dfs(Node* head) {
        if(!head) return NULL;
        Node* node = head;
        head->prev = pre;
        if(head->child && head->next) {
            auto next = head->next;
            head->next = head->child;
            head->child = NULL;
            pre = head;
            auto t = dfs(head->next);
            t->next = next;
            pre = t;
            node = dfs(t->next);
        } else {
            pre = head;
            if(head->next && !head->child) {
                node = dfs(head->next);
            }
            if(head->child && !head->next) {
                auto child = head->child;
                head->next = child;
                head->child = NULL;
                node = dfs(head->next);
            }
        }
        return node;
    }
};