/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while(even && even->next)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* oddPre = dummyNode->next;
        if(!oddPre) return head;
        ListNode* evenPre = dummyNode->next->next;
        if(!evenPre) return head;
        ListNode* t = evenPre;
        if(!evenPre || !evenPre->next) return head;
        while(oddPre && evenPre)
        {
            oddPre->next = oddPre->next->next;
            if(evenPre->next) {
                evenPre->next = evenPre->next->next;
            } else {
                break;
            }
            oddPre = oddPre->next;
            evenPre = evenPre->next;
        }
        oddPre->next = t;
        return dummyNode->next;
    }
};