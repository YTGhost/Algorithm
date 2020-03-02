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
        if(head == NULL || head->next == NULL)    return head;
        ListNode* L1 = head->next;
        ListNode* L2 = head;
        L2->next = NULL;
        while(L1 != NULL){
            ListNode* temp = L1;
            L1 = L1->next;
            temp->next = L2;
            L2 = temp;
        }
        return L2;
    }
};