/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l3->next = NULL;
    struct ListNode* t = l3;
    if(l1 == NULL && l2 == NULL){
        return NULL;
    }
    while(l1 != NULL && l2 != NULL){
        if(l1->val <= l2->val){
            t->val = l1->val;
            t->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            t = t->next;
            t->next = NULL;
            l1 = l1->next;
        }else{
            t->val = l2->val;
            t->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            t = t->next;
            t->next = NULL;
            l2 = l2->next;
        }
        if(l1 == NULL || l2 == NULL){
            break;
        }
    }

    if(l1 == NULL){
        while(l2 != NULL){
            t->val = l2->val;
            l2 = l2->next;
            if(l2 == NULL){
                break;
            }
            t->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            t = t->next;
            t->next = NULL;
        }
    }else{
        while(l1 != NULL){
            t->val = l1->val;
            l1 = l1->next;
            if(l1 == NULL){
                break;
            }
            t->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            t = t->next;
            t->next = NULL;
        }
    }
    return l3;
}