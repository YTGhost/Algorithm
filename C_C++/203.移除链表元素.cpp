/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* t = dummyNode;
        while(t && t->next) {
            if(t->next->val == val) {
                t->next = t->next->next;
            } else {
                t = t->next;
            }
        }
        return dummyNode->next;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* t = head;
        if(t == NULL){
            return t;
        }
        while(t->val == val){
            if(t->next == NULL){
                return NULL;
            }
            t = t->next;
            head = t;
        }
        while(t->next != NULL){
            if(t->next->val == val){
                t->next = t->next->next;
            }else{
                t = t->next;
            }
        }
        return head;
    }
};
// @lc code=end

