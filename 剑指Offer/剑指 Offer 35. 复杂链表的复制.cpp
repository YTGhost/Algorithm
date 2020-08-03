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
        if(!head) return NULL;

        for(auto node = head; node;)
        {
            auto next = node->next;
            auto newNode = new Node(node->val);
            node->next = newNode;
            newNode->next = next;
            node = next;
        }

        for(auto node = head; node; node = node->next->next)
        {
            if(node->random)
                node->next->random = node->random->next;
        }

        auto newNode = head->next;
        for(auto node = head; node && node->next;)
        {
            auto t = node->next;
            node->next = t->next;
            node = t;
        }
        return newNode;
    }
};