/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 递归
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head; 
        }
        ListNode* t = deleteDuplicates(head->next);
        if(head->val == t->val){
            head->next = head->next->next;
            delete t;
        }
        return head;
    }
};

// 迭代
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        auto dummy = new ListNode(0);
        dummy->next = head;
        while(head->next)
        {
            if(head->val == head->next->val)
            {
                head->next = head->next->next;
            }else head = head->next;
        }
        return dummy->next;
    }
};