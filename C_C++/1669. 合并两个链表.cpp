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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummyNode = new ListNode(-1, list1);
        ListNode* nodeA = list1;
        for(int i = 0; i < a - 1; i++) {
            nodeA = nodeA->next;
        }
        ListNode* nodeB = list1;
        for(int i = 0; i < b + 1; i++) {
            nodeB = nodeB->next;
        }
        ListNode* last = list2;
        while(last->next) {
            last = last->next;
        }
        nodeA->next = list2;
        last->next = nodeB;
        return dummyNode->next;
    }
};