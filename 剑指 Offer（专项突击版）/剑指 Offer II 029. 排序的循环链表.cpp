/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(!head) {
            Node *node = new Node(insertVal, NULL);
            node->next = node;
            return node;
        }
        Node *pre = head, *cur = head->next;
        bool toInsert = false;
        do {
            if(pre->val <= insertVal && insertVal <= cur->val) {
                toInsert = true;
            } else if(pre->val > cur->val) {
                if(insertVal >= pre->val || insertVal <= cur->val) {
                    toInsert = true;
                }
            }
            if(toInsert) {
                pre->next = new Node(insertVal, cur);
                return head;
            }
            pre = cur;
            cur = cur->next;
        } while(pre != head);
        pre->next = new Node(insertVal, cur);
        return head;
    }
};