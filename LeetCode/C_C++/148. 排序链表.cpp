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
// 自底向上（todo）

// 自顶向下，时间O(nlogn)，空间O(logn)
class Solution {
public:
    ListNode* findMid(ListNode* head, ListNode* tail) {
        ListNode* slow = head, *fast = head;
        while(fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if(fast != tail) {
                fast = fast->next;
            }
        }
        return slow;
    }
    ListNode* toSort(ListNode* head, ListNode* tail) {
        if(head == NULL) return head;
        if(head->next == tail) {
            head->next = NULL;
            return head;
        }
        ListNode* mid = findMid(head, tail);
        return merge(toSort(head, mid), toSort(mid, tail));
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(0);
        ListNode* temp = dummyNode;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if(l1) temp->next = l1;
        if(l2) temp->next = l2;
        return dummyNode->next;
    }
    ListNode* sortList(ListNode* head) {
        return toSort(head, NULL);
    }
};