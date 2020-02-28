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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        ListNode* p3 = head->next;
        if(head->next == NULL)
        {
            return NULL;
        }
        while(p2 != NULL)
        {
            if(n-- >= 0){
                p2 = p2->next;
            }else{
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        p1->next = p1->next->next;
        if(n == 0)  head = p3;
        return head;
    }
};