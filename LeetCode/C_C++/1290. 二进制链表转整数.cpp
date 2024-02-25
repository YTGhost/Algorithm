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
    int power = 0;
    int getDecimalValue(ListNode* head) {
        if(head == NULL)
        {
            return 0;
        }
        int decimalValue = getDecimalValue(head->next);
        if(head->val == 1)  decimalValue += pow(2, power++);
        else    power++;
        return decimalValue;
    }
};