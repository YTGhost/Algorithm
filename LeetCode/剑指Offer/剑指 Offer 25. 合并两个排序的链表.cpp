/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 迭代
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(0);
        auto head = dummy;
        
        while(l1 && l2)
        {
            if(l1->val <= l2->val){
                head->next = new ListNode(l1->val);
                l1 = l1->next;
                head = head->next;
            }else{
                head->next = new ListNode(l2->val);
                l2 = l2->next;
                head = head->next;
            }
        }
        if(l1) head->next = l1;
        else head->next = l2;
        return dummy->next;
    }
};

// 递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};