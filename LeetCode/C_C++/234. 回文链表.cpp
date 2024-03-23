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
    bool isPalindrome(ListNode* head) {
        function<ListNode*(ListNode*)> getPreHalf = [&](ListNode* head) {
            auto slow = head;
            auto fast = head;
            while(fast->next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        };
        function<ListNode*(ListNode*)> reverseList = [&](ListNode* head) {
            ListNode* prev = NULL;
            ListNode* cur = head;
            while(cur) {
                auto next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            return prev;
        };
        if(head == nullptr) {
            return true;
        }
        auto preHalfNode = getPreHalf(head);
        auto p1 = head;
        auto suf = reverseList(preHalfNode->next);
        auto p2 = suf;
        bool flag = true;
        while(p2) {
            if(p1->val != p2->val) {
                flag = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        preHalfNode->next = reverseList(suf);
        return flag;
    }
};

class Solution {
public:
    ListNode* middleNode(ListNode* node) {
        ListNode* slow = node;
        ListNode* fast = node;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* node) {
        ListNode* pre = NULL;
        ListNode* cur = node;
        while(cur) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* mid = middleNode(dummyNode);
        ListNode* temp = mid->next;
        mid->next = NULL;
        mid = reverse(temp);
        while(head && mid)
        {
            if(head->val != mid->val) return false;
            head = head->next;
            mid = mid->next;
        }
        return true;
    }
};