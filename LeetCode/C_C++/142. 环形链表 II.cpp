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
    ListNode *detectCycle(ListNode *head) {
        // a = (n - 1)(b + c) + c
        function<ListNode*(ListNode*)> isCycle = [&](ListNode *head) -> ListNode* {
            if(!head || !head->next) return NULL;
            ListNode *slow = head;
            ListNode *fast = head;
            while(fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast) return slow;
            }
            return NULL;
        };
        auto node = isCycle(head);
        if(!node) return NULL;
        auto ptr = head;
        while(ptr != node) {
            ptr = ptr->next;
            node = node->next;
        }
        return node;
    }
};

// 哈希表，空间复杂度O(n)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        while(head)
        {
            if(set.count(head)) return head;
            set.insert(head);
            head = head->next;
        }
        return head;
    }
};