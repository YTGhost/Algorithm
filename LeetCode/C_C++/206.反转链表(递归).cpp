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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        } else {
            auto node = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;
            return node;
        }
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }else{
            ListNode* t = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;
            return t;
        }
    }
};