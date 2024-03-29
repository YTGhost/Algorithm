class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while(fast && fast->next) {
            if(slow == fast) return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode *slow = head, *fast = head->next;
        while(slow != fast)
        {
            if(!fast || !fast->next) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return fast;
    }
};