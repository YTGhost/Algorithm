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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) {
            return list2;
        } else if(!list2) {
            return list1;
        } else if(list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto dummyNode = new ListNode(-1);
        auto ptr = dummyNode;
        while(list1 && list2) {
            if(list1->val <= list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        ptr->next = list1 ? list1 : list2;
        return dummyNode->next;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* head = dummyHead;
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
        while(l1)
        {
            head->next = new ListNode(l1->val);
            l1 = l1->next;
            head = head->next;
        }
        while(l2)
        {
            head->next = new ListNode(l2->val);
            l2 = l2->next;
            head = head->next;
        }
        return dummyHead->next;
    }
};