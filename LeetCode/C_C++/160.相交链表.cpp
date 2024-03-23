/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        auto p1 = headA, p2 = headB;
        while(p1 != p2) {
            p1 = p1 == nullptr ? headB : p1->next;
            p2 = p2 == nullptr ? headA : p2->next;
        }
        return p1;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode* pa = headA, *pb = headB;
        while(pa != pb) {
            pa = !pa ? headB : pa->next;
            pb = !pb ? headA : pb->next;
        }
        return pa;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> a;
        while(headA != NULL){
            a.insert(headA);
            headA = headA->next;
        }
        while(headB != NULL){
            if(a.find(headB) != a.end()){
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};
// @lc code=end

