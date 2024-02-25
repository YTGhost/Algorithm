/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;
        auto t1 = head;
        auto dummyNode = new Node(-1);
        auto t2 = dummyNode;
        while(t1 != NULL) {
            t2->next = new Node(t1->val);
            map[t1] = t2->next;
            t1 = t1->next;
            t2 = t2->next;
        }
        t1 = head;
        t2 = dummyNode;
        while(t1 != NULL) {
            t2->next->random = map[t1->random];
            t1 = t1->next;
            t2 = t2->next;
        }
        return dummyNode->next;
    }
};