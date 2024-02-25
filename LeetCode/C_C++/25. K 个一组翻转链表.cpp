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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyRoot = new ListNode(0);
        dummyRoot->next = head;
        ListNode* pre = dummyRoot;
        while(head)
        {
            ListNode* tail = pre;
            for(int i = 0; i < k; i++)
            {
                tail = tail->next;
                if(!tail) return dummyRoot->next;
            }
            ListNode* nex = tail->next;
            pair<ListNode*, ListNode*> t = reverse(head, tail);
            head = t.first;
            tail = t.second;
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }
        return dummyRoot->next;
    }

    pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail){
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(pre != tail)
        {
            ListNode* nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return {tail, head};
    }
};