/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        auto dummyNode = new ListNode(-1);
        dummyNode->next = head;
        auto ptr = dummyNode;
        while(ptr->next && ptr->next->next) {
            auto node1 = ptr->next;
            auto node2 = ptr->next->next;
            auto next = node2->next;
            ptr->next = node2;
            node2->next = node1;
            node1->next = next;
            ptr = ptr->next->next;
        }
        return dummyNode->next;
    }
};
// 递归
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)    return head;
        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};

// 迭代
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* temp = dummy;
        while(temp->next && temp->next->next)
        {
            ListNode* node1 = temp->next;
            ListNode* node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        return dummy->next;
    }
};