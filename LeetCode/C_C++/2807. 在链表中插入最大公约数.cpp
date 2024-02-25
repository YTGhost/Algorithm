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
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        auto p = head;
        while(p && p->next) {
            auto next = p->next;
            int t = gcd(p->val, next->val);
            auto newNode = new ListNode(t, next);
            p->next = newNode;
            p = next;
        }
        return head;
    }
};